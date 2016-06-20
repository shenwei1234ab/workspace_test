//============================================================================
// Name        : PipeLine.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
 #include <unistd.h>
#include<unistd.h>
#include <stdio.h>
#include <signal.h>>
using namespace std;

void handleSignUP(int id)
{
	printf("handleSignUP\n");
}

int main()
{
	::signal( SIGHUP ,handleSignUP);
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("child begin \n");
		sleep(5);
		printf("child end\n");
	}
	if(pid > 0 )
	{
		printf("parent begin \n");
		printf("parent end \n");
	}
	printf("all end pid =%d \n",getpid());
	return 0;
}
