#include <stdio.h>
#include <thread>                // std::thread, std::this_thread::yield
#include <mutex>                // std::mutex, std::unique_lock
#include <stdlib.h>
#include <iostream>
#include <pthread.h>

#define NLOOP 10
std::mutex mtx;

int n=0;
int counter=0;

void pFun()
{
	//mtx.lock();
	std::unique_lock<std::mutex> lck(mtx);
	for(int i=0;i<NLOOP;++i)
	{

		counter++;
		printf("thread :%u counter %d\n",(unsigned int )pthread_self(),counter);
	}
	//mtx.unlock();
}
int  main()
{
	std::thread thread1(pFun); //
	std::thread thread2(pFun);

	thread1.join();
	thread2.join();
	return 0;
}



