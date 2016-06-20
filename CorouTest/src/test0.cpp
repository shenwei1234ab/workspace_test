#include <stdio.h>
#include <ucontext.h>
#include <unistd.h>
#include <iostream>
int main(int argc, const char *argv[])
{
	int i=1;
	ucontext_t context;
	getcontext(&context);
	std::cout<<i<<std::endl;
	i++;
	puts("Hello world");
	sleep(1);
	setcontext(&context);
	return 0;
}
