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
#include <fcntl.h>
using namespace std;


//waitpid
int main(int arg,char *args[])
{
	char buf[1024] = "hello world \n";
	if (arg < 2)
	{
		printf("input pipe name");
		return 1;
	}
	int fd = open(args[1],O_WRONLY);
	write(fd,buf,strlen(buf));
	close(fd);
    return 0;
}






