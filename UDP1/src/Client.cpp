#include <stdio.h>
#include <stdlib.h>
#include "pub.h"
int main(int arg,char *args[])
{

	if(arg < 4 )
	{
		printf("usage:client host port filename\n");
		return EXIT_FAILURE;
	}

	int iport = atoi(args[2]);
	if(iport == 0)
	{
		return EXIT_FAILURE;
	}
	if(send_work(args[1],iport,args[3]) == 1)
	{
		printf("%s send success \n",args[3]);
	}
	else
	{
		printf("%s send failed \n",args[3]);
	}
	return EXIT_SUCCESS;

}
