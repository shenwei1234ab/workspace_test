//============================================================================
// Name        : thread1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
using namespace std;

void *func(void *arg)
{
	unsigned int i=0;
	printf("pthread start\n");
	while(1)
	{
		i++;
		printf("%u",i);
	}
}

void *func2(void *arg)
{
	unsigned int j=0;
	printf("pthread start\n");
	while(1)
	{
		j++;
		printf("%u",j);
	}
}



int main()
{
	pthread_t thrd;
	pthread_t thrd2;
	if(pthread_create(&thrd,NULL,func,NULL)!=0)
	{
		printf("error is %s \n",strerror(errno));
	}
	if(pthread_create(&thrd2,NULL,func2,NULL)!=0)
	{
		printf("error is %s \n",strerror(errno));
	}
	void **p=NULL;
	pthread_join(thrd,p);
	pthread_join(thrd2,p);
	return 0;
}
