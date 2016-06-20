#include <ucontext.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <iostream>
void func1(int i)
{
	std::cout<<"arg is :"<<i<<std::endl;
    puts("1");
    puts("11");
    puts("111");
    puts("1111");
}

void func2(void * arg)
{
	int *p = (int *)arg;
	std::cout<< p[0]<<std::endl;
    puts("1");
    puts("11");
    puts("111");
    puts("1111");
}


void context_test()
{
    char stack[1024*128];
    ucontext_t child,main;
    getcontext(&child); //保存当前上下文
    child.uc_stack.ss_sp = stack;//指定栈空间
    child.uc_stack.ss_size = sizeof(stack);//指定栈空间大小
    child.uc_stack.ss_flags = 0;
    child.uc_link = &main;//设置后继上下文
    makecontext(&child,(void (*)(void))func1,1,2);//创建上下文,修改上下文指向func1函数
   swapcontext(&main,&child);//保存当前上下文到main,切换到child上下文
  // getcontext(&main)  ;
  // setcontext(&child) ;
   puts("main");//如果设置了后继上下文，func1函数指向完后会返回此处
}

int main()
{
    context_test();
    puts("main return");
    return 0;
}
