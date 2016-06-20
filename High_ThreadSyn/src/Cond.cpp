
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
using namespace std;

/*
 *
 * 生产者和消费者模型(条件变量)
 *
 */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_cond = PTHREAD_COND_INITIALIZER;
#define CUSTOM_COUNT 2
#define PRODUCT_COUNT 4

int nNum = 5;
int nLoop = 4;
int g_count = 0;

void *consume(void *arg)
{
	long num = (long )arg;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(g_count == 0)		////////////醒来以后需要重新判断，可能是假醒，所以用while
		{
			printf("consumer%ldsleep\n",num);
			//条件等待，让生产者能获得锁，否则生产者一直阻塞获取不了锁，形成死锁
			pthread_cond_wait(&g_cond,&mutex);
			printf("consumer%ldawake\n",num);
		}
		g_count--;
		printf("consumer%ld consume\n",num);
		printf("current product number is %d\n",g_count);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	printf("consum : %ld\n",num);
	pthread_exit(NULL);
}


void *productError(void *arg)
{
	long num = (long )arg;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(g_count >= 10)
		{
			printf("g_count is too much \n");
			pthread_mutex_unlock(&mutex);
			sleep(2);
			continue;
		}
		g_count++;
		printf("product%ldproduct\n",num);
		printf("product%ldsendsignal\n",num);
		printf("current product number is %d\n",g_count);
		pthread_cond_signal(&g_cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_exit(NULL);
}


void *product(void *arg)
{
	long num = (long )arg;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(g_count >= 10)
		{
			printf("g_count is too many %d \n",g_count);
			pthread_mutex_unlock(&mutex);
			sleep(2);
			continue;
		}
		else
		{
			pthread_mutex_unlock(&mutex);
		}
		pthread_mutex_lock(&mutex);
		g_count++;
		printf("product%ldproduct\n",num);
		printf("current product number is %d\n",g_count);
		printf("product%ldsendsignal\n",num);
		pthread_cond_signal(&g_cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_exit(NULL);
}


int main()
{
	pthread_t tidArray[CUSTOM_COUNT+PRODUCT_COUNT];
 	for(int i=0;i<CUSTOM_COUNT;++i)
	{
		pthread_create(&tidArray[i],NULL,consume,(void *)i);
	}
 	sleep(1);

	for(int i=0;i<PRODUCT_COUNT;++i)
	{
		pthread_create(&tidArray[i+CUSTOM_COUNT],NULL,productError,(void *)i);
	}


	for(int i=0;i<CUSTOM_COUNT+PRODUCT_COUNT;++i)
	{
		pthread_join(tidArray[i],NULL);
	}
	printf("main exit\n");
	return 0;
}

