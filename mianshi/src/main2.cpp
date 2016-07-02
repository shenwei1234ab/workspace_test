//============================================================================
// Name        : thread2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "staticPar.h"
using namespace std;

//全局变量
 int g_id = 2;		//不能声明为static 静态变量或静态函数只有本文件内的代码才能访问它，它的名字在其它文件中不可见

 void stest()
{
	std::cout<<"stest"<<std::endl;
}
