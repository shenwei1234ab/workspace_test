//============================================================================
// Name        : Epoll1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
 #include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <sys/epoll.h>
#include <netdb.h>
using namespace std;

#define PORT 8000
typedef int SOCKET;
void setnonblocking(SOCKET st)
{
	int opts = fcntl(st,F_GETFL);
	if(opts < 0)
	{
		return;
	}
	opts = opts|O_NONBLOCK;
	if(opts < 0)
	{
		return ;
	}
	fcntl(st,F_SETFL,opts);
}

SOCKET socket_create(int port)
{
	SOCKET st = socket(AF_INET,SOCK_STREAM,0);
	int on=1;
	if(setsockopt(st,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) == -1)
	{
		return 0;
	}
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(st,(struct sockaddr *)&addr,sizeof(addr))  == -1)
	{

		return 0;
	}
	if(listen(st,300) == -1)
	{
		return 0;
	}
	return st;

}


SOCKET socket_accept(SOCKET listenSocket)
{
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);
	memset(&client_addr,0,sizeof(client_addr));
	SOCKET client_st =  accept(listenSocket,(struct sockaddr*)&client_addr,&len);
	if(client_st<0)
	{
		printf("accept failed\n");
	}
	return client_st;
}


int socket_recv(SOCKET clientSocket)
{
	char buf[1024];
	memset(buf,0,sizeof(buf));
	int rc = recv(clientSocket,buf,sizeof(buf),0);
	if(rc<=0)
	{
		printf("recv failed %s\n",strerror(errno));
	}
	else
	{
		//send(clientSocket,buf,rc,0);
		printf("recv success %s\n",buf);
	}
	return rc;
}



int main(int arg ,char* agrs[]) {
	/*if(arg < 2)
	{
		return -1;
	}*/
	//int port = atoi(agrs[1]);
	int port = PORT;
	SOCKET listen_st = socket_create(port);
	if(listen_st == 0)
	{
		return -1;
	}
	struct epoll_event ev,events[100];

	//创建epoll池
	int epfd = epoll_create(100);
	setnonblocking(listen_st);
	ev.data.fd = listen_st;
	ev.events = EPOLLIN|EPOLLERR|EPOLLHUP;
	//添加listen_Socket到epoll池中
	epoll_ctl(epfd,EPOLL_CTL_ADD,listen_st,&ev);

	while(1)
	{
		//返回epoll池中socket产生事件的数量
		printf("epoll_waiting .. \n");
		int nfds = epoll_wait(epfd,events,100,-1);
		if(nfds == -1)
		{
			printf("epoll_wait failed %s \n",strerror(errno));
			break;
		}
		for(int i=0;i<nfds;++i)
		{
			if(events[i].data.fd < 0)
			{
				continue;
			}
			if(events[i].data.fd  == listen_st)
			{
				printf("listen socket return \n");
				SOCKET st = socket_accept(listen_st);
				if(st >= 0)
				{
					printf(" socket accept \n");
					setnonblocking(st);
					ev.data.fd = st;
					ev.events = EPOLLIN|EPOLLERR|EPOLLHUP;
					epoll_ctl(epfd,EPOLL_CTL_ADD,st,&ev);
					continue;
				}
			}
			//socket 收到数据
			if(events[i].events & EPOLLIN)
			{
				printf("recv data \n");
				SOCKET st = events[i].data.fd;
				if(socket_recv(st) <= 0)
				{
					close(st);
					events[i].data.fd = -1;
				}
			}
			//socket 出错
			if(events[i].events & EPOLLERR)
			{
				SOCKET st = events[i].data.fd;
					close(st);
					events[i].data.fd = -1;
					//epoll会自动删除
					//epoll_ctl(epfd,EPOLL_CTL_DEL,st,&ev);
			}
			//client socket 被挂断
			if(events[i].events & EPOLLHUP)
			{
				SOCKET st = events[i].data.fd;
					close(st);
					events[i].data.fd = -1;
					//epoll会自动删除
					//epoll_ctl(epfd,EPOLL_CTL_DEL,st,&ev);
			}
		}
	}
	close(epfd);
	return 0;;

}























