#ifndef _SINA_
#define _SINA_
#include <iostream>
using namespace std;
class ASingleton
{
public:
	static ASingleton* getInstance()
	{
		static ASingleton instance;
		return &instance;
	}
	void do_something()
	{
		cout << "ASingleton do_something!" << endl;
	}
protected:
	struct Object_Creator
	{
		Object_Creator()
		{
			std::cout << "SingltonA obj" << std::endl;
			ASingleton::getInstance();
		}
	};
	static Object_Creator _object_creator;

	//static ASingleton m_data;
	ASingleton();
	~ASingleton() {}
};


#endif