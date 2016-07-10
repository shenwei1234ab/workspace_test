#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
using namespace std;


//递归求非波那且
int Fab1(int n)
{
	static int sum = 1;
	if(n<=0)
	{
		return	 sum;
	}
	sum= sum*n;
	Fab1(n-1);
}


int Fab2(int n)
{
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		sum = sum*i;
	}
	return sum;
}

