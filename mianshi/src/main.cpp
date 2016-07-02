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
#include "Linuxtest.h"
#include "statictest.h"
#include "duotaitest.h"
#include "statictest2.h"
#include "memorytest.h"
#include "sizeoftest.h"
#include "virtualtableTest.h"
using namespace std;

extern int g_id;
extern void stest();
int main()
{
	stest();
	std::cout<<g_id<<std::endl;
	std::cout<<"main"<<std::endl;
	statictest2();
	statictest2();
	return 0;
}


