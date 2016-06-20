#include <ucontext.h>
#include <stdio.h>
ucontext_t child1,umain,child2,uHandle;

bool bfinish1 = false;		//func1是否完成
bool bfinish2 = false;
int id = 0;
void func1(void * arg)
{
    puts("1");
    puts("11");
    swapcontext(&child1,&umain);//切换到main上下文，保存当前上下文到child1
    puts("111");
    puts("1111");
    //bfinish1 = true;
}



void func2(void *arg)
{
	puts("2");
	puts("22");
	swapcontext(&child2,&umain);//切换到main上下文，保存当前上下文到child2
	puts("222");
	puts("2222");
	//bfinish2 = true;
}


void Handler()
{
	while( id == 1 || id == 2)
	{
		if(id == 1)
		{
			bfinish1 = true;
		}
		else if(id == 2)
		{
			bfinish2 = true;
		}
		swapcontext(&uHandle,&umain);
	}

}


//实现context的切换
void context_test()
{
    char stack1[1024*1024];
    char stack2[1024*1024];
    char mainStack[1024*1024];
    char handlStack[1024*1024];
    getcontext(&child1); //获取当前上下文
    child1.uc_stack.ss_sp = stack1;//指定栈空间
    child1.uc_stack.ss_size = sizeof(stack1);//指定栈空间大小
    child1.uc_stack.ss_flags = 0;
    child1.uc_link = &uHandle;//设置后继上下文
    makecontext(&child1,(void (*)(void))func1,0);//修改上下文指向func1函数

    getcontext(&child2); //获取当前上下文
    child2.uc_stack.ss_sp = stack2;//指定栈空间
    child2.uc_stack.ss_size = sizeof(stack2);//指定栈空间大小
    child2.uc_stack.ss_flags = 0;
    child2.uc_link = &uHandle;//设置后继上下文
    makecontext(&child2,(void (*)(void))func2,0);//修改上下文指向func1函数

    getcontext(&umain); //获取当前上下文
    umain.uc_stack.ss_sp = mainStack;//指定栈空间
    umain.uc_stack.ss_size = sizeof(mainStack);//指定栈空间大小
    umain.uc_stack.ss_flags = 0;
    umain.uc_link = NULL;//设置后继上下文
   //makecontext(&child1,(void (*)(void))func1,0);//修改上下文指向func1函数





   getcontext(&uHandle); //获取当前上下文
   uHandle.uc_stack.ss_sp = handlStack;//指定栈空间
   uHandle.uc_stack.ss_size = sizeof(handlStack);//指定栈空间大小
   uHandle.uc_stack.ss_flags = 0;
   uHandle.uc_link = NULL;//设置后继上下文
   makecontext(&uHandle,(void (*)(void))Handler,0);//修改上下文指向func1函数




   while(1)
    {
    	if(bfinish1 && bfinish2)
    	{
    		puts("fun1 fun2 finished !!!");
    		break;
    	}
    	if(!bfinish1)
    	{
    		 swapcontext(&umain,&child1);//切换到child上下文，保存当前上下文到main
    		 puts("swapcontext 1");
    	}
    	if(!bfinish2)
    	{
    		 swapcontext(&umain,&child2);//切换到child上下文，保存当前上下文到main
    		 puts("swapcontext 2");
    	}
    	puts("...");
    }
    puts("main");//如果设置了后继上下文，func1函数指向完后会返回此处
}

int main()
{
    context_test();
    return 0;
}
