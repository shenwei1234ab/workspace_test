#include <stdio.h>
#include <stdlib.h>
#include "pub.h"
int main(int arg,char *args[])
{
	if(arg < 2 )
	{
		printf("usage:server listen port\n");
		return EXIT_FAILURE;
	}

	int iport = atoi(args[1]);
	if(iport == 0)
	{
		return EXIT_FAILURE;
	}
	if(recv_work(iport) == 1)
	{
		printf("%s recv success \n",args[1]);
	}
	else
	{
		printf("%s send failed \n",args[1]);
	}
	return EXIT_SUCCESS;

}
