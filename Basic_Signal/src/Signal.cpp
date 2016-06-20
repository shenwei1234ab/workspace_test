#include <stdlib.h>
#include <string.h>
#include <signal.h>
 #include <unistd.h>
#include <stdio.h>
void printsigset(const sigset_t *set)
{
	int i;
	for (i = 1; i < 32; i++)
	if (sigismember(set, i) == 1)
	putchar('1');
	else
	putchar('0');
	puts("");
}

//1.阻塞信号集测试
void SigSetTest()
{
	sigset_t s, p;
	sigemptyset(&s);				//自定义阻塞信号集
	sigaddset(&s, SIGINT);		//init信号 置为1
	sigprocmask(SIG_BLOCK, &s, NULL);	//注册到系统阻塞信号集
	while (1)
	{
		sigpending(&p);
		printsigset(&p);
		sleep(1);
	}
}


//2.捕捉函数测试
void  do_signal(int num)
{
	printf("I am do_sig\n");
	printf("num =%d\n",num);
}
void SigactionTest()
{
	struct sigaction act;
	act.sa_handler = do_signal;		//设置捕捉函数
	sigemptyset(&act.sa_mask);		//当捕捉函数执行时临时阻塞指定的信号防止干扰
	act.sa_flags = 0;
	//sigaction(SIGINT,&act,NULL);
	sigaction(SIGHUP,&act,NULL);
	while(1)
	{
		printf("。。。。。。。。\n");
		sleep(1);
	}
}

//3 时序竞态
int mySleep(int n)
{
	signal(SIGALRM,do_signal);
	//将下面两个变成原子操作
	alarm(n);			//1秒
	pause();
}


//4 sigchld信号回收子进程
void do_sig_child(int num)
{

}
void SigchldTest()
{
	std::cout<<"sigchldTest"<<std::endl;
	pid_t pid;
	int i;
	for(int i=0;i<2;++i)
	{
		if((pid = fork()) == 0)
		{
			//子进程
			break;
		}
	}
	if(pid == 0)
	{
		int n =8;
		while(n--)
		{
			printf("child ID %d\n",getpid());
			sleep(1);
		}
	}
	else if(pid > 0)
	{
		struct sigaction act;
		act.sa_handler = do_sig_child;
		act.sa_flags = 0;
		sigaction(SIGCHLD,&act,NULL);
		while(1)
		{

		}
	}
}
int main(int argc, char *argv[])
{
	SigactionTest();
	return 0;
}
