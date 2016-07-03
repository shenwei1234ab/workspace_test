#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
using namespace std;

class Base
{

public:

virtual void f() { cout << "Base::f" << endl; }

virtual void g() { cout << "Base::g" << endl; }

virtual void h() { cout << "Base::h" << endl; }

};


void vttest()
{
	std::cout<<sizeof(Base)<<std::endl;
	typedef void(*Fun)(void);

	Base b;

	Fun pFun = NULL;

	//cout << "虚函数表地址：" << (int*)(&b) << endl;

	//cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
}

