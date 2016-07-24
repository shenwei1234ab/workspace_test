#ifndef _SINGB_H
#define _SINGB_H
#include <iostream>
using namespace std;
class BSingleton
{
public:
	static BSingleton* getInstance()
	{
		static BSingleton instance;
		return &instance;
	}
	void do_something()
	{
		cout << "BSingleton do_something!" << endl;
	}
protected:
	struct Object_Creator
	{
		Object_Creator()
		{
			std::cout << "SingltonB obj" << std::endl;
			BSingleton::getInstance();
		}
	};
	static Object_Creator _object_creator;
	//static BSingleton m_data;
	BSingleton();
	~BSingleton() {}
};

#endif