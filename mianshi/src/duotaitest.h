#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>


#include<iostream>
using namespace std;
class A
{
public:
 virtual void print()
 {
  cout<<"A"<<endl;
 }
};
class B:public A
{
public:
 void print()
 {
  cout<<"B"<<endl;
 }
};
void duotaiTest()
{
	B b;

	A* t = new B();
	A& a=b;

	a.print();
	t->print();
}

