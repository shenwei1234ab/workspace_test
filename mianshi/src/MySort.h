#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
using namespace std;


void Swap(int *a1,int *a2)
{
	int tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}
void BubbleSort(int Array[],int nlength)
{
	for (int i = nlength; i >0; --i)
	{
		for (int j = 0; j < i-1; ++j)
		{
			if (Array[j] > Array[j + 1])
			{
				Swap(&Array[j], &Array[j + 1]);
			}
		}
	}
}

void Show(int Array[], int nlength)
{
	for (int i = 0; i < nlength; ++i)
	{
		std::cout << Array[i] << std::endl;
	}
}



/////////////////////////////////////////////////快速排序
void swap5(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
//划分过程 第一个元素当枢轴，分成2个有效子序列,左边比第一个元素小，右边比比第一个元素大
int partition(int array[], int low, int high)
{
	int pv = array[low];

	while (low < high)
	{
		while ((low < high) && (array[high] >= pv))
		{
			high--; //比基准大，本来就在右边，所以high前移动
		}
		swap5(array, low, high);
		while ((low < high) && (array[low] <= pv))
		{
			low++;
		}
		swap5(array, low, high);
	}
	//返回枢轴的位置。。。重要
	return low;
}

void QuickSort(int array[], int low,int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);
		QuickSort(array, low, pivot - 1);
		QuickSort(array, pivot+1, high);
	}
}





void SortTest()
{
	//int array[] = { 4, 5, 1, 23, 22 ,99,56};
	int array[] = { 4, 5, 1, 23, 22, 99, 56 };
	int len = sizeof(array) / sizeof(int);
	QuickSort(array, 0, len-1);
	Show(array, len);
}
