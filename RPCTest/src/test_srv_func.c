/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "test.h"
#include "time.h"

//////////////////////////远程函数test_1
char ** test_1_svc(char **argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */
	static char tmp_char[128];
	time_t rawtime;
	//自定义逻辑
	if (time(&rawtime) == ((time_t) -1))
	{
		strcpy(tmp_char, "Error");
		result = tmp_char;
		return &result;
	}
	sprintf(tmp_char, "服务器当前时间是 :%s", ctime(&rawtime));
	result = tmp_char;
	return &result;
}
