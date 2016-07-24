#include <iostream>
#include "Fab.h"
#include "MySort.h"
#include "statictest.h"
#include "KMP.h"
#include "DirtyManager.h"
#include "global.h"
#include "Manager.h"
#include "MyTree.h"
#include "MyDiGui.h"
class Point
{
public :
	Point()
	{
		std::cout << "Point" << std::endl;
	}

	
	Point(const Point &p)
	{
		std::cout << "copy Point" << std::endl;
	}

	~Point()
	{
		std::cout << "Point desconstruct" << std::endl;
	}
};


Point retTest1()
{

	Point ret;
	return ret;
}


Point retTest2()
{
	return Point();
}
void main1()
{
	Point b = retTest1();

	std::cout << "ÓÅ»¯ºó" << std::endl;

	Point c = retTest2();
	getchar();
}




void main()
{
	BiTreeTest2();
	getchar();
}