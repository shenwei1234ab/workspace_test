#include <iostream>
using namespace std;


class A
{
public:
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


class B : public A
{
public:
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

void test()
{
	int pArray[4] = { 1, 2, 3, 4 };
	int *p = pArray;
	printf("%p\n", pArray);
	printf("%p\n", pArray + 1); 
	printf("%p\n", p );
	printf("%p\n", p+1 );
}
void pFunTest()
{
	A *pA = new B();
	pA->g();
	cout << sizeof(A) << endl;
	//cout << sizeof(H) << endl;
	cout << sizeof(B) << endl;
	B b;
	Fun pFun;
	//取出虚函数指针：虚函数表的地址（存的都是虚函数的地址）
	printf("vtable address is %p\n", *(int*)(&b));
	printf("vtable address is %p\n", (int*)* (int*)(&b));
	for (int i = 0; i < 4; i++)
	{

		pFun = (Fun)*((int*)* (int*)(&b) + i);
		printf("fun address is %p\n", pFun);
		pFun();
	}
	//Fun pFun1 = (Fun)*((int *)*((int*)(&b) + 1));
	//pFun1();
	cin.get();
}



//总结：
//虚函数表指针一般在类的头部
//父类的按照顺序在前，子类在后