#include <stdio.h>
#include <iostream>
#include <event.h>
#include <evdns.h>
#include <event2/dns_struct.h>
#include <arpa/inet.h>
// libevent头文件
#include <event.h>
using namespace std;
////////////////////////////////////////////////////////////////////
// 定时事件回调函数
void onTime(int sock, short event, void *arg)
{
	cout << "Game Over!" << endl;

	struct timeval tv;
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	// 重新添加定时事件（定时事件触发后默认自动删除）
	event_add((struct event*) arg, &tv);
}

void TimerTest()
{
	// 初始化
	event_init();

	struct event evTime;
	// 设置定时事件
	evtimer_set(&evTime, onTime, &evTime);

	struct timeval tv;
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	// 添加定时事件
	event_add(&evTime, &tv);
	// 事件循环
	event_dispatch();
}
////////////////////////////////////////////////////////////////////
void dns_callback(int result,char type,int count,int ttl,void *addresses,void *arg)
{
	char *ip = (char *)arg;
	struct in_addr *addrs = (in_addr *)addresses;
	if(result != DNS_ERR_NONE || count == 0)
	{
		printf("result : %s",evdns_err_to_string(result));
	}
	else
	{
		char *ip = inet_ntoa(addrs[0]);
		printf("%s",ip);
	}
		event_loopexit(NULL);
}
void dnsServerTest()
{
	char buf[129];
	evdns_init();
	evdns_resolve_ipv4("www.baidu.com",0,dns_callback,buf);
	event_dispatch();
}
int main()
{
	dnsServerTest();
	getchar();
	return 1;
}

