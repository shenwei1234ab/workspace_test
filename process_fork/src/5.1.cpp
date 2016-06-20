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

//创建一个孤儿进程,这个孤儿进程能申城100个僵死进程
//int main(int arg,char *args[])
//{
//	pid_t pid = fork();
//	int status=0;
//	if(pid < 0)
//	{
//		printf("fork failed \n");
//		return -1;
//	}
//	//father process
//	if(pid > 0)
//	{
//		printf("father process start \n");
//		wait(&status);
//		sleep(25);
//		printf("father process stop \n");
//		//exit(0);
//	}
//	//son process
//	if(pid == 0)
//	{
//		printf("son process start \n");
//		printf("son process stop \n");
//		return 10;
//	}
//	return 0;
//}
int main(int arg,char *args[])
{
	pid_t pid=0;
	for(int i=0;i<3;++i)
	{
		 pid = fork();
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
		printf("father process start \n");
		//wait(&status);
		sleep(25);
		printf("father process stop \n");
		//exit(0);
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



