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
	if((pid = fork()) < 0)
	{
		printf("error");
		exit(1);
	}
	else if( pid == 0)
	{
		//子进程
		printf("child process PID is %d\n",getpid());
		printf("child GID is %d\n",getpgid(0));
		sleep(5);
		printf("Group ID of child is changed to %d\n",getpgid(0));
		exit(0);
	}
	sleep(1);
	setpgid(pid,pid); // 父进程改变子进程的组id为子进程本身
	sleep(5);
	printf("parent process PID is %d\n",getpid());
	printf("parent of parent process PID is %d\n",getppid());
	printf("Group ID of parent is %d\n",getpgid(0));
	setpgid(getpid(),getppid()); // 改变父进程的组id为父进程的父进程
	printf("Group ID of parent is changed to %d\n",getpgid(0));




	return 0;
}






