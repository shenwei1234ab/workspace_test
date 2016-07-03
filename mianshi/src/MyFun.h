#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include <list>

int MyAtoi(const char *pStr)
{
	assert(pStr!=NULL);
	int ret = 0;
	std::list<char> mList;
	for(;*pStr!='\0';pStr++)
	{
		if(*pStr <'0' || *pStr > '9')
		{
			break;
		}
		mList.push_back(*pStr);
	}
	for(auto it=mList.rbegin();it!=mList.rend();++it)
	{
		static int n=1;
		char val = *it;
		ret += (val -'0' +0)*n;
		n=n*10;
	}
	return ret;
}



int atoiTest()
{
	int n;
	const char *str="12345";
	//n = atoi(str);
	n=MyAtoi(str);
	printf("int=%d\n",n);
	return n;
}
