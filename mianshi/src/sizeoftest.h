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

#pragma pack(1)
struct foo
{
  char c1;
  short s;
  char c2;
  int i;
 };
#pragma pack()
class foo2
{
public:
int m_a;
short int m_b;
double m_c;
private:
int m_d;
public:
	int GetValue(){ return m_c; }
};

//http://www.cppblog.com/xczhang/archive/2007/12/23/39396.html

void sizeofTest()
{
	std::cout<<sizeof(int)<<std::endl;
	std::cout<<sizeof(short)<<std::endl;
	//向最大数据成员对齐
	std::cout<<sizeof(foo)<<std::endl;	//12
	std::cout<<sizeof(foo2)<<std::endl;
}

//简单算法：
//每个成员大小为最宽基本类型成员的整数倍
//总大小为最宽基本类型成员的整数倍

//详细
//1.结构体每个成员变量的大小能够被最宽基本类型成员的大小所整除
//2.结构体每个成员相对与结构体首地址的偏移量都是成员大小的整数背
//3.结构体的总大小为结构体最宽基本类型成员大小的整数倍




