//============================================================================
// Name        : thread2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "staticPar.h"
#include "DirtyManager.h"
using namespace std;
class Father
{
public:
	int id;
	void test()
	{
		std::cout<<"main2 Father"<<std::endl;
	}
};

//全局变量
 int g_id = 2;		//不能声明为static 静态变量或静态函数只有本文件内的代码才能访问它，它的名字在其它文件中不可见


 static int s_tt = 2;
 void stest()
{
	 s_tt = 4;
	 Father f;
	 f.test();
	std::cout<<"stest"<<std::endl;
}
