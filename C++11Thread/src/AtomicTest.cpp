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
#include <atomic>
#include <unistd.h>
using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int nNum = 4;
int nLoop = 5000;
int count=0;
std::atomic_int g_num(0);
//int g_num=0;
struct ThreadInfo
{
	int threadid;
};

void *routine(void *arg)
{

	for(int i=0;i<nLoop;++i)
	{
		//pthread_mutex_lock(&mutex);
		int val=count;
		printf("%x:%d\n",(unsigned int )pthread_self(),val+1);
		count = val+1;
		//pthread_mutex_unlock(&mutex);
	}
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
	//printf("%d \n",g_num.load(std::memory_order_relaxed));
	std::cout<<g_num<<std::endl;
	printf("main exit\n");
	return 0;
}

