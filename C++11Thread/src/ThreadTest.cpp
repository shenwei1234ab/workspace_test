//============================================================================
// Name        : Process.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdlib.h>
#include <iostream>
#include <map>
#include <list>
#include <stdio.h>
#include <thread>
#include <functional>
#include<unistd.h>
using namespace std;

void myThread(int n)
{
	printf("n=%d\n",n);

		printf("myThread\n");
		sleep(5);

}
int main()
{
	std::thread t1(&myThread,1);//创建一个分支线程，回调到myThread函数里
	t1.detach();
	sleep(2);
	//t1.join();
	printf("main return \n");
	return 0;
}



