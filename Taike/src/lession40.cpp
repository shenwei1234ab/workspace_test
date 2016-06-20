#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
class Base
{
public:
	Base()
	{
		std::cout<<"Base construct"<<std::endl;
	}

	~Base()
	{
		std::cout<<"Base desconstruct"<<std::endl;
	}


};

class Son
{
public:
	Son()
	{
		std::cout<<"Son construct"<<std::endl;
	}

	~Son()
	{
		std::cout<<"Son desconstruct"<<std::endl;
	}


public:
	std::list<Base > m_base;
};

void test2()
{
	Base *pBase = new Base();
	Son s;
	s.m_base.push_back(*pBase);
}

int main()
{
	test2();

    return 0;
}
