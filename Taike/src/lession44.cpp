#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
#include <memory>
//智能指针
//shared_pointer
class Object
{
public:
	Object(int id):m_id(id)
	{
		std::cout<<"Object()"<<std::endl;
	}
	~Object()
	{
		std::cout<<"~Object()"<<std::endl;
	}
	int id()const
	{
		return m_id;
	}
private:
	int m_id;
};
typedef std::shared_ptr<Object> ObjectPtr;
typedef std::weak_ptr<Object> WeakObjectPtr;
void deleterofObject(Object *pobj)
{
	if(pobj)
	{
		std::cout<<"delete obj"<<pobj->id()<<std::endl;
		delete pobj;
	}
}

void print(ObjectPtr obj)
{
	std::cout<<"count "<<obj.use_count()<<"id"<<obj->id()<<std::endl;
}


void printRef(const ObjectPtr &obj)
{
	std::cout<<"ref count "<<obj.use_count()<<"id"<<obj->id()<<std::endl;
}


void interfaceofSharedPtr()
{
	ObjectPtr obj(new Object(1));
	std::cout<<"ref count is" <<obj.use_count()<<std::endl;
	WeakObjectPtr weakObj(obj);
	WeakObjectPtr weakObj2(obj);
	print(obj);
	auto p =weakObj.lock();
	if(p)
	{
		std::cout<<p.unique()<<std::endl;
	}
	//值传入会改变引用计数（+1）
	//print(obj);
	//printRef(obj);


/*

	ObjectPtr obj2(obj);
	std::cout<<"ref count is" <<obj.use_count()<<std::endl;
	obj2.reset();		//不要了，引用计数-1
	//obj2 = nullptr;
	std::cout<<"ref count is" <<obj.use_count()<<std::endl;
*/

}

int main()
{
	interfaceofSharedPtr();
	return 0;
}




