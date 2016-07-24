#include "SingletonA.h"
#include "SingletonB.h"

ASingleton::Object_Creator ASingleton::_object_creator;
//ASingleton ASingleton::m_data;
ASingleton::ASingleton()
{
	cout << "ASingleton constructor!" << endl;
	BSingleton::getInstance()->do_something();
}