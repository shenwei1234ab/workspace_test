//============================================================================
// Name        : shmem.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <sys/ipc.h>
#include <sys/shm.h>
 #include <stdlib.h>
#include <stdio.h>
using namespace std;

void attach()
{

}

int main(int arg,char *args[])
{
	void *shmbuf;
	int shmid=0;
	if(arg >2)
	{
		shmid = atoi(args[1]);
		shmbuf=shmat(shmid,0,0);
		//write
		if(atoi(args[2]) ==1)
		{
			scanf("%s",shmbuf);
		}
		if(atoi(args[2]) ==2)
		{
			printf("%s\n",shmbuf);
		}
		shmdt(shmbuf);
	}
	return 0;
}
