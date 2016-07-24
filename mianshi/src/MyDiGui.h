#ifndef _MY_DIGUI_H
#define _MY_DIGUI_H
#include <iostream>
#include <stack>
using namespace std;
struct datas
{
	int n;
	void(*p)(int);
};
void  Print(int n) 
{
	if (n == 0)
	{
		return ;
	}
	std::cout << n;
	Print(n - 1);
}

void  Print2(int n)
{
	stack<int> mystack;
AAA:
	if (n > 0)
	{
		mystack.push(n);
		while (!mystack.empty())
		{
			cout << mystack.top();
			mystack.pop();
		}
		n -= 1;
		goto AAA;
	}	
}

void  Print3(int n)
{
	stack<int> mystack;
AAA:
	if (n > 0)
	{
		mystack.push(n);
		n -= 1;
		goto AAA;
	}
	while (!mystack.empty())
	{
		cout << mystack.top();
		mystack.pop();
	}
}

void print(int n)
{
	std::cout << n << std::endl;
}
void  Print4(int n)
{
	stack<datas> mystack;
AAA:
	if (n > 0)
	{
		datas s1;
		s1.n = n;
		s1.p = print;
		mystack.push(s1);
		while (!mystack.empty())
		{
			datas stemp = mystack.top();
			stemp.p(stemp.n);
			mystack.pop();
		}
		n -= 1;
		goto AAA;
	}
	
}


int  GetSum(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	return GetSum(n - 1) + n;
}


int  GetSum2(int n)
{
	stack<int> mystack;
AAA:
	if (n)
	{
		mystack.push(n);
		n -= 1;
		goto AAA;
	}

	int ret = 0;
	while (!mystack.empty())
	{
		ret += mystack.top();
		mystack.pop();
	}
	return ret;
}


void to2(int num)
{
	if (num)
	{
		std::cout << num % 2 << std::endl;
		to2(num / 2);
	}
}






void DiguiTest()
{	
	Print4(5);
}
#endif