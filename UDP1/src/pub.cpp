#include "pub.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
 #include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#define BUFSIZE 1024



SOCKET init_socket()
{
	return 0;
}

SOCKET create_send_socket()
{
	if(init_socket() == -1)
	{
		return 0;
	}
	SOCKET st = socket(AF_INET,SOCK_DGRAM,0);
	if(st == 0)
	{
		return 0;
	}
	return st;
}

SOCKET create_recv_socket(int port)
{
/*	if(init_socket() == -1)
	{
		return 0;
	}*/
	SOCKET st = socket(AF_INET,SOCK_DGRAM,0);
	if(st == 0)
	{
		return 0;
	}
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(st,(struct sockaddr *)&addr,sizeof(addr)) ==-1)
	{
		printf("bind failed %s\n",strerror(errno));
		return 0;
	}
	return st;
}


SOCKET socket_accept(SOCKET listen_st)
{
	struct sockaddr_in client_addr;
	unsigned int len = 1;
	len = sizeof(client_addr);
	memset(&client_addr,0,sizeof(client_addr));
	SOCKET client_st = accept(listen_st,(struct sockaddr *)&client_addr,&len);
	if(client_st == -1)
	{
		return 0;
	}
	else
	{
		return client_st;
	}
}

//client : readfilename
//send filecontext to server
int send_work(const char *phost,int port,const char *pfilename )
{
	SOCKET st_send =create_send_socket();
	SOCKET st_recv =create_recv_socket(port+1);
	if(st_send == 0)
	{
		return 0;
	}
	if(st_recv == 0)
	{
		return 0;
	}
	FILE *pFd = fopen(pfilename,"rb");
	if(pFd == NULL)
	{
		printf("open %s file failed %s\n",pfilename,strerror(errno));
		return 0;
	}
	char *pbuf =(char *) malloc(BUFSIZE);
	memset(pbuf,0,BUFSIZE);
	strcpy(pbuf,pfilename);
	//getfilename(pfilename,pbuf);

	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr=inet_addr(phost);
	printf("client send file:%s to %s:%d\n",pfilename,phost,port);
	size_t rc = sendto(st_send,pbuf,strlen(pbuf),0,(struct sockaddr *)&addr,sizeof(addr));
	if(rc == -1)
	{
		printf("send to server failed :%s\n ",strerror(errno));
		return -1;
	}
	else
	{
		printf("send to server success\n");
		struct sockaddr_in client_addr;
		memset(&client_addr,0,sizeof(client_addr));
		unsigned int len = sizeof(client_addr);
		memset(pbuf,0,BUFSIZE);
		if(recvfrom(st_recv, pbuf,  BUFSIZE, 0,
                (struct sockaddr *)&client_addr, &len) <0)
		{
			printf("recv %s from server failed : %s\n",pbuf,strerror(errno));
		}
		else
		{
			//printf("receive message from %s\n",inet_ntoa(client_addr.sin_addr));
			if(strncmp(pbuf,"OK",2) == 0)
			{
				while(1)
				{
					memset(pbuf,0,BUFSIZE);
					//rc = fread(pbuf,1,BUFSIZE,pFd);
					read(STDIN_FILENO,pbuf,BUFSIZE);
					if(strncmp("end",pbuf,3) == 0)
					{
						break;
					}
					else
					{
						rc = sendto(st_send,pbuf,strlen(pbuf),0,(struct sockaddr *)&addr,sizeof(addr));
						if(rc < 0)
						{
							printf("send failed");
							break;
						}
					}
				}

			}
			memset(pbuf,0,BUFSIZE);
			rc = sendto(st_send,pbuf,128,0,(struct sockaddr *)&addr,sizeof(addr));
		}
	}
	fclose(pFd);
	close(st_send);
	close(st_recv);
	return 1;
}

//server
int recv_work(int port)
{
	SOCKET st_send =create_send_socket();
	SOCKET st_recv =create_recv_socket(port);
	if(st_send == 0)
	{
		return 0;
	}
	if(st_recv == 0)
	{
		return 0;
	}
	else
	{
		printf("server is listening.......\n");
	}
	unsigned int len=1;
	struct sockaddr_in client_addr;
	len = sizeof(client_addr);
	memset(&client_addr,0,sizeof(client_addr));
	char *pbuf =(char *) malloc(BUFSIZE);
	memset(pbuf,0,BUFSIZE);
	if(recvfrom(st_recv, pbuf,  BUFSIZE, 0,
            (struct sockaddr *)&client_addr, &len) < 0 )
	{
		printf("recv failed:\n",strerror(errno));
	}
	else
	{
		printf("receive message from %s\n",inet_ntoa(client_addr.sin_addr));
		printf("filename is %s\n",pbuf);
	   FILE *pFile =fopen(pbuf,"wb");
	   if(pFile == NULL)
	   {
		   printf("open file failed\n");
	   }
	   else
	   {
		   client_addr.sin_port = htons(port+1);
		   memset(pbuf,0,BUFSIZE);
		   strcpy(pbuf,"OK");
		   //printf("send ok to %d len is %d\n",client_addr.sin_port,strlen(pbuf));

		   if( sendto(st_send,pbuf,strlen(pbuf),0,(struct sockaddr *)&client_addr,sizeof(client_addr))<0)
		   {
			   printf("server send ok failed\n");
		   }
		   else
		   {
			   while(1)
			   {
				   	   memset(pbuf,0,BUFSIZE);
				   	   int rc = recvfrom(st_recv,pbuf,BUFSIZE,0,(struct sockaddr*)&client_addr,&len);
				   	   char tmp[128];
				   	   memset(tmp,0,sizeof(tmp));
				   	   if(memcmp(pbuf,tmp,sizeof(tmp)) == 0)
				   	   {
				   		   break;
				   	   }
				   	   else
				   	   {
				   		   	   fwrite(pbuf,1, rc,pFile);
				   	   }
			   }

		   }
	   }
	   if (pFile)
	   {
		   fclose(pFile);
	   }
	}
	free(pbuf);



}




