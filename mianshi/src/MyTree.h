#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
using namespace std;
void clean_stdin()
{
 int c;
 do {
  c = getchar();
 } while (c != '\n' && c != EOF);
}

typedef struct BiNode
{
	char data;
	BiNode *pLeft;
	BiNode *pRight;
}*BiTree;


//先序创建2叉数
void  CreateTreePre(BiTree &pRoot)
{
	char data;
	//printf("Enter Data space is end \n");
	scanf("%c",&data);
	//fflush(stdin);  不起作用
	clean_stdin();
	if(data == '#')
	{
		pRoot = NULL;
	}
	else
	{
		pRoot = new BiNode();
		pRoot->data =data;
		CreateTreePre(pRoot->pLeft);
		CreateTreePre(pRoot->pRight);
	}
	return;
}

//先序遍历2查树(根，左，右)
void PrintTreePre(BiTree pRoot)
{
	if(!pRoot)
	{
		return;
	}
	printf("%c\n",pRoot->data);
	PrintTreePre(pRoot->pLeft);
	PrintTreePre(pRoot->pRight);
}

void BiTreeTest()
{
	BiTree p =new BiNode();
	CreateTreePre(p);
	PrintTreePre(p);
}
