#include "SingletonB.h"


BSingleton::Object_Creator BSingleton::_object_creator;

//BSingleton BSingleton::m_data;

BSingleton::BSingleton()
{
	cout << "BSingleton constructor!" << endl;
}