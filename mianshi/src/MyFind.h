#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
using namespace std;

//二分查找 ,返回value在parray中的位置
int BinarySearch(int *pArray,int num,int value)
{
	int minIndex = 0;
	int maxIndex = num -1;
	while(minIndex <= maxIndex)
	{
		int mid = minIndex+maxIndex;
		if(pArray[mid] == value)
		{
			return mid;
		}
		else if (pArray[mid] < value)
		{
			minIndex = mid+1;
		}
		else
		{
			maxIndex=mid - 1;
		}
	}
	return -1;
}

void SearchTest()
{
	int ret = -1;
	int pArray[]={1,2,3,18,29,100,200};
	if((ret=BinarySearch(pArray,7,101))<0)
	{
		std::cout<<"not found"<<std::endl;
	}
	else
	{
		std::cout<<" found"<<ret<<std::endl;
	}

}
