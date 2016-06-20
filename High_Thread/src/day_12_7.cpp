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

int nNum = 5;
int nLoop = 4;

struct ThreadInfo
{
	int threadid;
};

void *routine(void *arg)
{
	//pthread_detach(pthread_self());
	ThreadInfo *td = (ThreadInfo *)arg;
	printf("%x \n",td);
	for(int i=0;i<nLoop;++i)
	{
		printf("pthread %u:run id =%d\n",(unsigned int )pthread_self(), td->threadid);
	}
	pthread_exit(NULL);
}
//多线程易范错误：

int main0()
{
	pthread_t tidArray[200];
	printf("thread num is %d\n",nNum);
	for(int i=0;i<nNum;++i)
	{
		ThreadInfo tmp;
		memset(&tmp,0,sizeof(tmp));
		tmp.threadid = i;
		pthread_create(&tidArray[i],NULL,routine,&tmp);
	}
	for(int i=0;i<nNum;++i)
	{
		pthread_join(tidArray[i],NULL);
	}
	printf("main exit\n");
	return 0;
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
