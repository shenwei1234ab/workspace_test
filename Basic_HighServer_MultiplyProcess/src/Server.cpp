#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
 #include <ctype.h>
#include "wrap.h"
 #include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define SERV_PORT 8000
void do_sigchild(int num)
{
	waitpid(0, NULL, WNOHANG);
}

//UDP server少了listen 和accept
int main(void)
{
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int listenfd, connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int i, n;
	pid_t pid;



	struct sigaction newact;
	newact.sa_handler = do_sigchild;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGCHLD, &newact, NULL);

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	printf("listenfd is %d\n",listenfd);
	bzero(&servaddr, sizeof(servaddr));
	memset(&cliaddr,0,sizeof(cliaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Listen(listenfd, 20);
	printf("Accepting connections ...\n");
	while (1)
	{
		cliaddr_len = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
		printf("client connect to server %s\n",inet_ntoa(cliaddr.sin_addr));
		printf("connfd is %d\n",connfd);
		pid = fork();
		//children process
		if (pid == 0)
		{
			Close(listenfd);
			while (1)
			{
				n = Read(connfd, buf, MAXLINE);
				if (n == 0)
				{
					printf("the other side has been closed.\n");
					break;
				}
				printf("received from %s at PORT %d\n",
				inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
				ntohs(cliaddr.sin_port));
				for (i = 0; i < n; i++)
				{
					buf[i] = toupper(buf[i]);
				}
				Write(connfd, buf, n);
			}
			Close(connfd);
			return 0;
		}
		else if (pid >0 )
		{
			//Close(connfd);
		}
		else
		{
			perr_exit("fork");
		}
	}
}



