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
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int nNum = 5;
int nLoop = 4;

int g_num=0;
struct ThreadInfo
{
	int threadid;
};

bool if_routineMain=true;
//routine1 10 routine 10         routine1 100 routine 10
void *routineMain(void *arg)
{

	for(int i=0;i<5;++i)
	{
		pthread_mutex_lock(&mutex);
		if(!if_routineMain)
		{
			pthread_cond_wait(&cond,&mutex);
		}
		for(int j=0;j<5;++j)
		{
			printf(" routineMain loop j:%d   i:%d\n",j,i);
		}
		if_routineMain = false;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}



void *routineSub(void *arg)
{

	for(int i=0;i<5;++i)
	{
		pthread_mutex_lock(&mutex);
		if(if_routineMain )
		{
			pthread_cond_wait(&cond,&mutex);
			for(int j=0;j<5;++j)
			{
				printf(" routineSub loop j:%d   i:%d\n",j,i);
			}
			if_routineMain = true;
			pthread_cond_signal(&cond);
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t tidArray[200];
	ThreadInfo threadinfoArray[nNum];

	pthread_create(&tidArray[0],NULL,routineMain,NULL);
	pthread_create(&tidArray[1],NULL,routineSub,NULL);
	pthread_join(tidArray[0],NULL);
	pthread_join(tidArray[1],NULL);
	printf("main exit\n");
	return 0;
}




