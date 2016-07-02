#include <stdio.h>

class StaticFather
{
public:
	StaticFather()
	{
		std::cout<<"StaticFather"<<std::endl;
	}


	~StaticFather()
	{
		std::cout<<"~StaticFather"<<std::endl;
	}
};


void statictest2()
{
	std::cout<<"statictest2"<<std::endl;
	static StaticFather fa[2];

}

