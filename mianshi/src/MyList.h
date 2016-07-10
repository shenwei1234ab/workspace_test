#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
using namespace std;
//单链表,有个头节点指针指向头节点，头节点可以存链表长度
typedef struct Node
{
	int data=-1;
	struct Node *pNext=NULL;
}Node,*LinkList;


//创建单链表(头插)
//p指向头节点的指针
void CreateListHeadByHeadInsert(LinkList &p,int n)
{
	srand(time(0));
	//创建头节点
	Node *pHead = new Node();
	pHead->pNext = NULL;
	//头节点指针指向头节点
	p = pHead;
	for(int i=0;i<n;++i)
	{
		//创建新节点
		Node *pNew = new Node();
		pNew->data = i;
		//插入到表头
		pNew->pNext = pHead->pNext;
		pHead->pNext = pNew;
	}
}

//尾插
void CreateListHeadByTailInsert(LinkList &p,int n)
{
	srand(time(0));
	//创建头节点
	Node *pHead = new Node();
	pHead->pNext = NULL;
	//头节点指针指向头节点
	p = pHead;
	//创建尾节点
	Node *pTail = pHead;
	for(int i=0;i<n;++i)
	{
		//创建新节点
		Node *pNew = new Node();
		pNew->data = i;
		//尾节点插入
		pTail->pNext = pNew;
		pTail = pNew;
	}
}


//遍历链表
void PrintList(LinkList p)
{
	for(Node *pIndex = p->pNext;pIndex!=NULL;pIndex=pIndex->pNext)
	{
		std::cout<<pIndex->data<<std::endl;
	}
}

//测长度
int GetLength(LinkList p)
{
	int len=0;
	for(Node *pIndex=p->pNext;pIndex!=NULL;pIndex=pIndex->pNext)
	{
		len++;
	}
	return len;
}

//在nindex之前插入节点
//p:指向头节点的指针 ,n:元素的位置
bool MyListInsert(LinkList p,int nIndex,int nVal)
{
	Node *pIndex= p;//指向所找节点的上一个节点
	int index=0;
	while(p&&index < nIndex-1)
	{
		pIndex=pIndex->pNext;
		index++;
	}
	if(!p || index>nIndex-1)
	{
		return  false;
	}
	Node *pNew =new Node();
	pNew->data = nVal;
	pNew->pNext = pIndex->pNext;
	pIndex->pNext = pNew;
	return true;
}


bool MyListDelete(LinkList p,int nIndex)
{
	Node *pIndex= p;//指向所找节点的上一个节点
		int index=0;
		while(p&&index < nIndex-1)
		{
			pIndex=pIndex->pNext;
			index++;
		}
		if(!p->pNext || index>nIndex-1)
		{
			return  false;
		}
		Node *pDelete = p->pNext;
		p->pNext = pDelete->pNext;
		delete pDelete;
		return true;
}




//测试代码
void MyListTest()
{
	Node *pNode;
	//CreateListHeadByHeadInsert(pNode,6);
	CreateListHeadByTailInsert(pNode,6);
	PrintList(pNode);
	std::cout<<"list lenth is :"<<GetLength(pNode)<<std::endl;
}


