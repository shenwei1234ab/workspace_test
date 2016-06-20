//============================================================================
// Name        : thread2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <list>
using namespace std;
//
int main()
{
	int 	ret = 0;
	MYSQL 	mysql;
	MYSQL	*connect = NULL;
	connect = mysql_init(&mysql) ;
	if (connect == NULL)
	{
		ret = mysql_errno(&mysql);
		printf("func mysql_init() err \n");
		return ret;
	}
	printf("func mysql_init() ok \n");
	connect = mysql_real_connect(connect, "localhost", "root", "root", "test", 0, NULL, 0);
	if (connect == NULL)
	{
		ret = -1;
		printf("func mysql_init() err \n");
		return ret;
	}
	printf("func mysql_real_connect() ok \n");
	//设置编码
	ret = mysql_query(&mysql, "set names utf8");
	if (ret != 0)
	{
		ret =  mysql_errno(&mysql) ;
		printf("func mysql_query() err \n");
		return ret;
	}

	//执行sql语句
	const char *query="select * from work";
	ret = mysql_query(&mysql,query);
	if(ret !=NULL)
	{
		ret =  mysql_errno(&mysql) ;
		printf("ret =%d\n",ret);
		const char *pErr = mysql_error(&mysql);
		printf("func mysql_query() err %s\n",pErr);
		return ret;
	}

	//获取所有的结果集
	MYSQL_RES *result = mysql_store_result(&mysql);
	//使用的过程中在获取 结果
	//MYSQL_RES *result = mysql_use_result(&mysql);


	//获取列数
	unsigned int num = mysql_field_count(&mysql);
	//获取表头
	MYSQL_FIELD *fields=mysql_fetch_fields(result);
	for(int i=0;i<num;++i)
	{
		printf("%s\t",fields[i].name);
	}
	printf("\n");
	//二级指针
	MYSQL_ROW row = NULL;
	while (row = mysql_fetch_row(result) )
	{
		for(int i=0;i<num;++i)
		{
			printf("%s\t",row[i]);
		}
		printf("\n");
	}
	mysql_close(&mysql);
	printf("hello...\n");
	return ret;
	}
