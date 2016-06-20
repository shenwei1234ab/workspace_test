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
#include <thread>

using namespace std;
void thread_task() {
    std::cout << "hello thread" << std::endl;
}


int main()
{
	std::thread t(thread_task);
	t.join();
	return 0;
}




