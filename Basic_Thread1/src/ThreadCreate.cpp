#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void *th_fun(void *arg)
{
	int *p = (int *)arg;
	printf(" thread PID=%d\n",getpid());
	printf(" thread ID=%x\n",(unsigned int )pthread_self());
	printf("thread *arg = %d\n",*p);

	exit(0);
}



int main()
{
	pthread_t tid;
	int n=10;

	pthread_create(&tid,NULL,th_fun,(void *)&n);

	printf("main thread ID=%x\n",(unsigned int )pthread_self());
	printf("main child thread ID=%x\n",(unsigned int )tid);
	printf("main PID=%d\n",getpid());

	sleep(10);
	return 0;
}
