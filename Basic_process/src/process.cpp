//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

//wait
int main0(int arg,char *args[])
{
	pid_t pid=0;
	for(int i=0;i<3;++i)
	{
		 printf("fork\n");
		 pid = fork();
		 printf("fork after\n");
		 if(pid == 0)
		 {
			 break;
		 }
	}
	int status=0;
	if(pid < 0)
	{
		printf("fork failed \n");
		return -1;
	}
	//father process
	if(pid > 0)
	{
		//sleep(10);
		printf("father process start \n");
		//返回子进程的process_id
		//pid_t childPid = wait(&status);
		//printf("father process stop child process id is %d\n",childPid);
		while(1)
		{

		}
	}
	//son process
	if(pid == 0)
	{
		printf("son process start \n");
		printf("son process stop \n");
		return 10;
	}
	return 0;
}
//waitpid
int main(int arg,char *args[])
{
	int n=0;
	pid_t pid=0;
	//创建2个子进程
	for(int i=0;i<2;++i)
	{
		 pid = fork();
		 if(pid == 0)
		 {
			 break;
		 }
	}
	int status=0;
	//father process
	if(pid > 0)
	{
		//sleep(10);
		printf("father process start \n");
		printf("father 's processid is %d\n",getpid());
		//返回子进程的process_id
		//pid_t childPid = wait(&status);
		//printf("father process stop child process id is %d\n",childPid);
		while(1)
		{

			if(waitpid(0,&status,WNOHANG) == -1)		//非阻塞回收子进程（0表示同组的）
			{
				//没有子进程要回收了
				printf("waitpid exit");
				break;
			}
		}
	}
	//son process
	if(pid == 0)
	{
		printf("i am child %d n=%d \n",getpid(),n);
		sleep(10);
		printf("son process start \n");
		printf("son process stop \n");
		return 10;
	}
	return 0;
}






