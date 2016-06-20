//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
using namespace std;

void do_signal(int n)
{
	printf("catch n");
}

void CreateSession()
{
	pid_t pid;
	if((pid = fork())<0)
	{
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child process PID is %d\n",getpid());
		printf("GroupID is %d\n",getpgid(0));		//查看当前组的组id
		printf("sessionID is %d\n",getsid(0));//查看当前session的sessionid
		sleep(10);
		setsid();	//子进程非组长进程，所以能成为新会话首进程,且成为进程组组长。
		printf("changed\n");
		printf("child process PID is %d\n",getpid());
		printf("GroupID is %d\n",getpgid(0));		//查看当前组的组id
		printf("sessionID is %d\n",getsid(0));//查看当前session的sessionid
		sleep(200);
		exit(0);
	}
}


void CreateNoHunp()
{
	//问题：这种也能起到和创建session相同的作用？
	struct sigaction act;
	act.sa_handler = do_signal;		//设置捕捉函数
	sigemptyset(&act.sa_mask);		//当捕捉函数执行时临时阻塞指定的信号防止干扰
	act.sa_flags = 0;
	//sigaction(SIGINT,&act,NULL);
	sigaction(SIGHUP,&act,NULL);
	while(1)
	{

	}
}

void GetCurTime()
{

}
void CreateDaemon()
{
	char buf[1024];
	time_t t;
	time(&t);	//获取秒数	距离1970.1.1 00：00：00的秒数
	ctime_r(&t,buf);//转化为时间格式
	std::cout<<buf<<std::endl;
}
//waitpid
int main(int arg,char *args[])
{
	CreateDaemon();
	return 0;
}






