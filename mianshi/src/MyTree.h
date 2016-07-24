
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
#include <stack>


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
	BiNode *pLeft=NULL;
	BiNode *pRight=NULL;
}*BiTree;


//先序创建2叉数
void  CreateTreePre(BiTree &pRoot)
{
	char data;
	//printf("Enter Data space is end \n");
	scanf_s("%c",&data);
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

//中序遍历2查树(，左，根,右)
void PrintTreePre(BiTree pRoot)
{
	if(!pRoot)
	{
		return;
	}
	
	PrintTreePre(pRoot->pLeft);
	printf("%c\n", pRoot->data);
	PrintTreePre(pRoot->pRight);
}

//利用栈中序遍历
//1.如果节点有左子树，节点入栈
//2.如果节点没有有左子树，访问节点
//3.如果节点有右子树，重复步骤1，
//4.如果节点没有右子树，栈顶元素弹出
void StackZhong(BiTree pRoot)
{
	BiNode * pcurr = pRoot;//记录根节点
	stack<BiNode *> mystack;

	while (!mystack.empty() || pcurr != nullptr)
	{
		while (pcurr != nullptr)
		{
			mystack.push(pcurr);

			pcurr = pcurr->pLeft;
		}

		if (!mystack.empty())
		{
			pcurr = mystack.top();
			cout << "  " << pcurr->data << endl;

			mystack.pop();
			pcurr = pcurr->pRight;
		}
	}
}

void BiTreeTest()
{
	BiTree p =new BiNode();
	CreateTreePre(p);
	PrintTreePre(p);
}



void BiTreeTest2()
{
	BiTree pRoot = new BiNode();


	BiTree p2 = new BiNode();
	BiTree p3 = new BiNode();
	BiTree p4 = new BiNode();
	BiTree p5 = new BiNode();
	BiTree p6 = new BiNode();
	BiTree p7 = new BiNode();


	pRoot->data = '1';
	p2->data = '2';
	p3->data = '3';
	p4->data = '4';
	p5->data = '5';
	p6->data = '6';
	p7->data = '7';

	pRoot->pLeft = p2;
	pRoot->pRight = p3;


	
	p2->pLeft = p4;
	p2->pRight = p5;



	p3->pLeft = p6;
	p3->pRight = p7;
	PrintTreePre(pRoot);
	std::cout <<"////////////////////////////////////" <<std::endl;
	StackZhong(pRoot);
}

