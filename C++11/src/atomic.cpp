//============================================================================
// Name        : thread2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int nNum = 5;
int nLoop = 4;

int g_num=0;
struct ThreadInfo
{
	int threadid;
};

void *routine(void *arg)
{
	//pthread_mutex_lock(&mutex);
	g_num++;
	printf("thread :%u g_num is %d\n",pthread_self(),g_num);
	//pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main()
{
	pthread_t tidArray[200];
	printf("thread num is %d\n",nNum);
	ThreadInfo threadinfoArray[nNum];
 	for(int i=0;i<nNum;++i)
	{
 		threadinfoArray[i].threadid = i;
		pthread_create(&tidArray[i],NULL,routine,&threadinfoArray[i]);
	}
	for(int i=0;i<nNum;++i)
	{
		pthread_join(tidArray[i],NULL);
	}
	printf("main exit\n");
	return 0;
}

