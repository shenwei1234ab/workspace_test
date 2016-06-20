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

//反转单恋表
struct Node
{
	Node *next=NULL;
	int value;
};


void PrintList(Node *pHead)
{
	while(pHead)
	{
		printf("value:%d ",pHead->value);
		pHead = pHead->next;
	}
}

Node * RevertList(Node *pHead)
{
	Node *pCur = pHead;
	while(pHead->next)
	{
		Node *pNew = new Node();
		pNew->value = pHead->next->value;
		pNew->next = pCur;
		Node *pNext = pHead->next;
		pHead->next=NULL;
		pHead = pNext;
		pCur = pNew;
	}
	return	pCur;
}

void Test()
{
	Node *pHead = new Node;
	pHead->value = 0;
	Node *pCur = pHead;
	for(int i=1;i<3;++i)
	{
		Node *pTail = new Node();
		pTail->value =	i;
		pCur->next = pTail;
		pCur = pTail;
	}
	PrintList(pHead);
	Node *pNew  = RevertList(pHead);
	PrintList(pNew);
}
//waitpid
int main(int arg,char *args[])
{
	Test();
	return 0;
}






