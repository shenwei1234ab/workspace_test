#include <iostream>
#include <stdlib.h>
#include "myList.h"
using namespace std;
//class AASingleton
//{
//public:
//	static AASingleton* getInstance()
//	{
//		return &m_data;
//	}
//	void do_something()
//	{
//		std::cout << "AASingleton do_something!" << std::endl;
//	}
//protected:
//	static AASingleton m_data; //static data member 在类中声明，在类外定义
//	AASingleton();
//	~AASingleton() {}
//};
//
//class BBSingleton
//{
//public:
//	static BBSingleton* getInstance()
//	{
//		return &m_data;
//	}
//	void do_something()
//	{
//		std::cout << "BBSingleton do_something!" << std::endl;
//	}
//protected:
//	static BBSingleton m_data; //static data member 在类中声明，在类外定义
//	BBSingleton();
//	~BBSingleton() {}
//};
//
//AASingleton AASingleton::m_data;
//BBSingleton BBSingleton::m_data;
//
//AASingleton::AASingleton()
//{
//	cout << "AASingleton constructor!" << endl;
//	BBSingleton::getInstance()->do_something();
//}
//
//BBSingleton::BBSingleton()
//{
//	cout << "BBSingleton constructor!" << endl;
//}
void main()
{
	ListTest();
	getchar();
}