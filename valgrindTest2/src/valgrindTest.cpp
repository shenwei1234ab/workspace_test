#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
static void mem_leak1(void)
{
    char *p = (char *)malloc(1);
}

static void mem_leak2(void)
{
    FILE *fp = fopen("test.txt", "w");
}


static void Array_over(void)
{
	int a[4]={};
	a[4]=1;

}
static void mem_overrun1(void)
{
    char *p = (char *)malloc(1);
    *(short*)p = 2;

    free(p);
}

static void mem_overrun2(void)
{
    char array[5];
    strcpy(array, "hello");
}



static void mem_double_free(void)
{
    char *p =(char *) malloc(1);
    free(p);
    free(p);
}

static void mem_use_wild_pointer(void)
{
    char *p = (char*)0x80184800;
    *p = 1;
}

static void mem_free_wild_pointer(void)
{
    char *p;
    free(p);
}




int main()
{
	//Array_over();
	int i;
	std::cout<<i<<std::endl;
    mem_leak1();
    mem_leak2();
   mem_overrun1();
   mem_overrun2();
   // mem_double_free();
    //mem_use_wild_pointer();
   // mem_free_wild_pointer();

    return 0;
}
