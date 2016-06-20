#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

class RuleOfFive
{
public:
	RuleOfFive(const RuleOfFive &rhs):m_value(new int(*rhs.m_value))//const引用同时可以接收左值和右值
	{

	}

	RuleOfFive(RuleOfFive &&rhs)
	{
		std::cout<<"rightvalue construct"<<std::endl;
		m_value = rhs.m_value;
		rhs.m_value = nullptr;
	}


	RuleOfFive():m_value(new int(10))
	{

	}

	void printf()
	{
		std::cout<<*m_value<<std::endl;
	}
	~RuleOfFive()
	{
		delete m_value;
	}
private:
	int *m_value;
};
int main()
{
	RuleOfFive b;
	RuleOfFive e =b;
	RuleOfFive d =std::move(b);
	b.printf();			//不要使用了
    return 0;
}
