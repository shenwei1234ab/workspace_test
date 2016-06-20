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
#include <stdio.h>
using namespace std;


int main()
{

	int shmid=shmget(IPC_PRIVATE,1024,0666);
	if(shmid<0)
	{
		cout<<"create failed"<<endl;
	}
	else
	{
		cout<<"create  success"<<endl;
		printf("shmid is %d\n",shmid);
	}
	return 0;
}
