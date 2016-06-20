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


//waitpid
int main(int arg,char *args[])
{
	pid_t pid;
	if((pid = fork())<0)
	{
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child process PID is %d\n",getpid());
		printf("GroupID is %d\n",getpgid(0));		//查看当前组的组id
		printf("sessionID is %d\n",getsid(0));//查看当前session的sessionid
		sleep(10);
		setsid();	//子进程非组长进程，所以能成为新会话首进程,且成为进程组组长。
		printf("changed\n");
		printf("child process PID is %d\n",getpid());
		printf("GroupID is %d\n",getpgid(0));		//查看当前组的组id
		printf("sessionID is %d\n",getsid(0));//查看当前session的sessionid
		sleep(200);
		exit(0);
	}
	return 0;
}






