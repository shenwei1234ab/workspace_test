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



/////////////////////////////////////////////////��������
void swap5(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
//���ֹ��� ��һ��Ԫ�ص����ᣬ�ֳ�2����Ч������,��߱ȵ�һ��Ԫ��С���ұ߱ȱȵ�һ��Ԫ�ش�
int partition(int array[], int low, int high)
{
	int pv = array[low];

	while (low < high)
	{
		while ((low < high) && (array[high] >= pv))
		{
			high--; //�Ȼ�׼�󣬱��������ұߣ�����highǰ�ƶ�
		}
		swap5(array, low, high);
		while ((low < high) && (array[low] <= pv))
		{
			low++;
		}
		swap5(array, low, high);
	}
	//���������λ�á�������Ҫ
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
