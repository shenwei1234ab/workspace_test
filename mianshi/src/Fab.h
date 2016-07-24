#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
#include <queue>
#include <stack>
using namespace std;


//递归求非波那且
//int Fab1(int n)
//{
//	static int sum = 1;
//	if(n<=0)
//	{
//		return	 sum;
//	}
//	sum= sum*n;
//	Fab1(n-1);
//}
//
//
//int Fab2(int n)
//{
//	int sum=1;
//	for(int i=1;i<=n;i++)
//	{
//		sum = sum*i;
//	}
//	return sum;
//}


//递归求解
int GetFab(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return GetFab(n - 1) + GetFab(n - 2);
	}
}

//数组求解
int GetFab2(int n)
{
	int *p = new int[n+1];
	p[0] = 0;
	p[1] = 1;
	for (int i = 2; i <=n; ++i)
	{
		p[i] = p[i - 1] + p[i - 2];
	}
	int ret = p[n];
	delete[]p;
	return ret;
}

//轮替法求解
int GetFab3(int n)
{
	 int sum = 1;
	 int f1 = 0;
	 int f2 = 1;
	 int f3 = 1;
	for (int i = 2; i <= n; ++i)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}

//stack求解
int GetFab4(int n)
{
	stack<int> mystack;
	int f1, f2, f3;
	f1 = f2 = 1;
	int i = 2;
ABC:
	if (i < n)
	{
		mystack.push(f1);
		mystack.push(f2);
		f3 = 0;
		while (!mystack.empty())
		{
			f3 += mystack.top();
			mystack.pop();
		}
		f1 = f2;
		f2 = f3;
		i++;
		goto ABC;
	}
	return f3;
}

//queue
int GetFab5(int n)
{
	int sum = 1;
	queue<int> mqu;
	mqu.push(0);
	mqu.push(1);
	for (int i = 2; i <= n; ++i)
	{
		int sum = mqu.front() + mqu.back();
		mqu.pop();
		mqu.push(sum);
	}
	return mqu.back();
}



void FabTest()
{
	std::cout << GetFab(7) << std::endl;
	std::cout << GetFab2(7) << std::endl;
	std::cout << GetFab3(7) << std::endl;
	std::cout << GetFab4(3) << std::endl;
}