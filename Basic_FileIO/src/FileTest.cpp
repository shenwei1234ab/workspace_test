//============================================================================
// Name        : thread2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//r+   写在源文件的头
//a+   卸载原文件的尾巴
//w+ ，如果文件已经存在，将建立一个新文件覆盖原文件（很缺德啊……），并且支持读取





int  main1()
{
	FILE *pfile = fopen("example.txt","r");
	if( pfile == NULL)
	{
		printf("file not found\n");
	}
	else
	{
		int size = ftell(pfile);
		printf("size is %d \n",size);
		char pArray[size];
		fgets(pArray,size,pfile);
		printf("%s \n",pArray);
	}
	  return 0;
}



//fseek
int  main()
{
	//FILE *pfile = fopen("test.txt","r+");
	//FILE *pfile = fopen("test.txt","a+");

	  FILE * pFile;
	  pFile = fopen ( "example.txt" , "wb" );
	  fputs ( "This is an apple." , pFile );
	  //返回文件字节数
	  int size = ftell(pFile);
	  printf("file size is %d \n",size);
	  fseek ( pFile , 1 , SEEK_SET );
	  //从T 后面追加写
	  fputs ( " sam" , pFile );




	  size++;
	  //读
	  char pArray[size];
	  		fgets(pArray,size,pFile);
	  		printf("%s \n",pArray);
	  fclose ( pFile );
	  return 0;
}

