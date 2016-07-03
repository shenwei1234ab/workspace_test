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
#include "MyFun.h"
#include "StrTest.h"
#include "MyString.h"
using namespace std;

extern int g_id;
extern void stest();

int Sum( int n )
{
	return ( (long)1 + n) * n / 2;
}
int main()
{
	CString str1("shenwei");
	CString str2("shenbin");
	CString s3 = str1+str2;
	return 0;
}


