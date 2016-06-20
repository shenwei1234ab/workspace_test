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
using namespace std;

void f(void)
{
	int *p=new int;
	delete p;
	int* pArray = new int[1];
	pArray[10] = 0; // problem 1: heap block overrun
} // problem 2: memory leak -- x not freed
void test()
{
	std::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
}
int main() {
	/*int i;
	f();
	while(1)
	{

	}
	printf("i=%d/n",i); //problem 3: use uninitialised value.*/
	test();
	return 0;
}
