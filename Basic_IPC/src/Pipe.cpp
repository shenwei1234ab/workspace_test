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


int main(int arg,char *args[])
{
	int fd[2];
	char str[1024]="hello world";
	pid_t pid;
	//先pipe后fork
	if(pipe(fd) < 0)
	{
		printf("pipe error\n");
		exit(1);
	}
	pid = fork();
	//father
	if(pid > 0)
	{
		//close(fd[0]);
		write(fd[1],str,strlen(str));
		wait(NULL);
	}
	//son
	else if (pid == 0)
	{
		char buf[1024];
		//close(fd[1]);
		read(fd[0],buf,1024);
		//printf("%s \n ",buf);
		write(STDOUT_FILENO,buf,strlen(buf));
	}

	return 0;
}






