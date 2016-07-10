#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
using namespace std;

class AA
{
	//int num;
	virtual void g()
	{
		cout << "A::g" << endl;
	}
private:
	virtual void f()
	{
		cout << "A::f" << endl;
	}
	virtual void j()
	{
		cout << "A::j" << endl;
	}
};


class BB : public AA
{
	void g()
	{
		cout << "B::g" << endl;
	}
	virtual void h()
	{
		cout << "B::h" << endl;
	}
};
typedef void(*Fun)(void);


void vtableTest()
{
	cout << sizeof(AA) << endl;
	cout << sizeof(BB) << endl;
	BB b;
	Fun pFun;

	for (int i = 0; i < 3; i++)
	{
		//pFun是指向虚函数表的指针
		pFun = (Fun)*((int*)* (int*)(&b) + i);
		pFun();
	}
	//Fun pFun1 = (Fun)*((int *)*((int*)(&b) + 1));
	//pFun1();
	cin.get();
}
