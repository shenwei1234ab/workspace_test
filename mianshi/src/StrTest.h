#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include <list>
//http://blog.csdn.net/piaojun_pj/article/details/5945926
class CFather
{
public:
	CFather()
	{
		std::cout<<"sFather"<<std::endl;
	}
	char c1;
	short s;
	char c2;
	int i;
};


void MemTest()
{
	char array[20];
	const char *p="123";
	memcpy(array,"123",4);
	std::cout<<array<<std::endl;
	CFather f;
}

void strTest()
{
	char string[10]={1,2,3,4,5,6,7,8,9,'\0'};
	const char* str1 = "0123456789";
	std::cout<<strnlen(string,sizeof(string))<<std::endl;
   strncpy( string, str1,sizeof(string));
   //snprintf(string,sizeof(string),"%s",str1);
   std::cout<<string<<std::endl;
}
