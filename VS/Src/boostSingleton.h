#ifndef _BOOST_SINGLE_H
#define _BOOST_SINGLE_H

#include <iostream>

//http://blog.csdn.net/crayondeng/article/details/24853471
class Singleton
{
public:
	static Singleton* getInstance()
	{
		static Singleton instance;
		return &instance;
	}

protected:
	//代理做某事
	struct Object_Creator
	{
		Object_Creator()
		{
			std::cout << "Object_Creator constructor" << std::endl;
			Singleton::getInstance();
		}
	};
	static Object_Creator _object_creator;

	Singleton() { std::cout << "Singleton constructor" << std::endl; }
	~Singleton() {}
};
Singleton::Object_Creator Singleton::_object_creator;



#endif