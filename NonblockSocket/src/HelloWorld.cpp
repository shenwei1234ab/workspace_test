//============================================================================
// Name        : HelloWorld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {
	/*int i=1;
	int j=2;
	std::list<int > myList;
	myList.push_back(1);
	myList.push_back(2);
	std::map<int,int> myMap;
	myMap[0] = 0;
	myMap[1] = 1;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!*/
	//char s[1024] = "test";
	//char s2[]="test";
	while(1)
	{
			char contxt[1024];
			memset(contxt,0,sizeof(contxt));
			read(STDIN_FILENO,contxt,sizeof(contxt));
			printf("\n input is %s\n",contxt);
			if(strcmp("test",contxt) == 0)
			{
				printf("s == s2");
			}
			else
			{
				printf("s != s2");
			}
	}

	return 0;
}
