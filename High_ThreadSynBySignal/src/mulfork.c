#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <signal.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#include "myipc_sem.h"
#include "myipc_shm.h"

#include <pthread.h>

int g_key = 0x3333;

void TestFunc(int loopnum)
{
	printf("loopnum:%d\n", loopnum);
	
	int ncount = 0;
	int ret = 0;
	int shmhdl = 0;
	int *addr = NULL;
	
	int semid = 0;
	sem_open(g_key, &semid);


 	sem_p(semid); //�ٽ���ʼ
	//
		ret = IPC_CreatShm(".", 0, &shmhdl);
		
		ret =IPC_MapShm(shmhdl, (void **)&addr);
		*((int *)addr) =  *((int *)addr)  + 1;
		ncount = *((int *)addr);
		printf("ncount:%d\n", ncount);
		//addr[0] = addr[0] +1;
		ret =IPC_UnMapShm(addr);
		//sleep(2);
		
	sem_v(semid);  //�ٽ���ʼ
	//
	printf("������˳�:%d\n", getpid());
}	



//posix �߳̿�ĺ��� �߳̿�
void *thread_routine(void* arg)
{
	printf("thread_routine start\n");
	TestFunc(1);
	pthread_exit(0);

} 

int main(void )
{
	int res;
    int procnum=10;
	int loopnum = 100;
	
	pthread_t tidArray[200];


	int  i=0;

	printf("������Ҫ�����ӽ�̵ĸ��� : \n");
	scanf("%d", &procnum);

	printf("��������ÿ���ӽ�̲��Զ��ٴ� :\n");
	scanf("%d", &loopnum);
	
	//�����ڴ洴��
	int		ret = 0;
	int 	shmhdl = 0;
	ret = IPC_CreatShm(".", sizeof(int), &shmhdl);
	if (ret != 0)
	{
		printf("func IPC_CreatShm() err:%d \n", ret);
		return ret;
	}
	
	
	//�ź����Ĵ���
 	int  	semid = 0;
	ret = sem_creat(g_key, &semid);
	if (ret != 0)
	{
		printf("func sem_creat() err:%d,���°���open���ź��� \n", ret);
		if (ret == SEMERR_EEXIST)
		{
			ret = sem_open(g_key, &semid);
			if (ret != 0)
			{
				printf("���մ򿪵ķ�ʽ�����»�ȡsemʧ��:%d \n", ret);
				return ret;
			}
		}
		else
		{
			return ret;
		}
		
	}
	
	int  val = 0;
	ret = sem_getval(semid, &val);
	if (ret != 0 )
	{
		printf("func sem_getval() err:%d \n", ret);
		return ret;
	}
	printf("sem val:%d\n", val);
	getchar();
	
	for (i=0; i<procnum; i++)
	{
	
		//tmp.numId = i; //��˵�� �̺߳�����ʹ����һ�����ϱ仯���ڴ�ռ䡣������
		pthread_create(&tidArray[i], NULL, thread_routine, NULL);
	}
	
	for (i=0; i<procnum; i++)
	{
		pthread_join(tidArray[i], NULL); //�ȴ��߳̽�����
	}


	printf("������˳� hello...\n");
	return 0;
}




