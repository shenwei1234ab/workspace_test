//============================================================================
// Name        : thread2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


void StrTest()
{
	const char *s = "Golden Global View";
	char *d;
	d = strdup(s);
	if (NULL != d)
		printf("%s\n", d);
	free(d);
}

int main()
{
	StrTest();
	return 0;
}

