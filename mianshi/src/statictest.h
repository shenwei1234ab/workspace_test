//============================================================================
// Name        : thread2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
using namespace std;

int f(int);
int staticTest()
{
    int ret;
    ret = f(3);
    cout<<"main: ret = "<<ret<<endl;
    ret = f(1);
    cout<<"main: ret = "<<ret<<endl;
    return 0;
}
int f(int a)
{
    static int b = 2;
    cout<<"f: b = "<<b<<endl;
    b = b+a;
    cout<<"f: b = "<<b<<endl;
    return b;
}


class MyLog
{
public :
	MyLog()
	{
		std::cout << "myLog" << std::endl;
	}
	~MyLog()
	{
		std::cout << "myLog" << std::endl;
	}
};




