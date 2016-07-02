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

void memoryTest()
{
	char s1[]="aaaa";
	char *ps1 = s1;
	const char *s2="bbbbbb";

	*(ps1+1)= 'b';
	std::cout<<s1<<std::endl;
	std::cout<<s2<<std::endl;
}





