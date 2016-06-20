//============================================================================
// Name        : CoreTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void dummy_function (void)
{
	unsigned char *ptr = 0x00;
	*ptr = 0x00;
}


void test()
{
	dummy_function();
}
int main() {
	test ();
	cout << "Hello World!!!" << endl; // prints Hello World!!!
	return 0;
}
