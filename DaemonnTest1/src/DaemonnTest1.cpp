//============================================================================
// Name        : DaemonnTest1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <signal.h>
#include <stdio.h>
using namespace std;

void init(int test)
{
	printf("init\n");
}


void kill(int test)
{
	printf("kill\n");
}




int main()
{
	signal(SIGINT,init);
	signal(SIGTERM,kill);
	while(1)
	{

	}
	cout << "Hello World!!!" << endl; // prints Hello World!!!
	return 0;
}
