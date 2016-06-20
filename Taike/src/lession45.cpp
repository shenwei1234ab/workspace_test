#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
#include <memory>
//weakptr 打破循环引用
class Father;
class child
{
public:
	//Father f;
	child()
	{
		std::cout<<"child "<<std::endl;
	}
	~child()
	{
		std::cout<<"~child "<<std::endl;
	}
};
class Father
{
public:
	//child c;
	Father()
	{
		std::cout<<"Father "<<std::endl;
	}
	~Father()
	{
		std::cout<<"~Father "<<std::endl;
	}
};


void weakPtrTest()
{
}



int main()
{
	weakPtrTest();
	return 0;
}




