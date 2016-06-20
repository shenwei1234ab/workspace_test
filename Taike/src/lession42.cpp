#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>

class A
{
public:
	 explicit A(double value):m_value(value){}
private :
	 //好习惯
	double m_value{};
};
int main()
{
	//报错  隐士转化A tmp(2.2)			a(tmp)   ~tmp
	//A a=2.2;

	//改进
	A a{2.2};
    return 0;
}
