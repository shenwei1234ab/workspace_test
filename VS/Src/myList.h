#ifndef _MYLIST_H
#define _MYLIST_H

#include <iostream>
typedef struct Node
{
	int val;
	Node *pNext = nullptr;
}Node, *LinkList;



void CreateList(LinkList &pNode, int n)
{
	Node *pHead = new Node();
	pNode = pHead;
	Node *pTail = pHead;
	for (int i = 0; i < n; ++i)
	{
		Node *pNode = new Node();
		pNode->val = i;
		pTail->pNext = pNode;
		pTail = pNode;
	}
}


void ShowList(LinkList pNode)
{
	for (Node *pIndex = pNode->pNext; pIndex != nullptr; pIndex = pIndex->pNext)
	{
		std::cout << pIndex->val << std::endl;
	}
}

bool InsertList(LinkList pNode, int n, int val)
{
	int i = 0;
	Node *pIndex = pNode->pNext;
	while (pIndex && i < n-1)
	{
		pIndex = pIndex->pNext;
		i++;
	}
	if (!pIndex || i>n-1)
	{
		return false;
	}
	Node *pNew = new Node();
	pNew->val = val;
	pNew->pNext = pIndex->pNext;
	pIndex->pNext = pNew;
	return true;
}


bool DeleteList(LinkList pNode, int n, int *val)
{
	int i = 0;
	Node *pIndex = pNode->pNext;
	while (pIndex && i < n - 1)
	{
		pIndex = pIndex->pNext;
		i++;
	}
	if (!pIndex || i> n - 1)
	{
		return false;
	}
	Node *p = pIndex->pNext;
	pIndex->pNext = p->pNext;
	*val = p->val;
	free(p);
	return true;
}



//得到单链表的某项值
bool GetElem(LinkList pNode, int index, int *pValue)
{
	int i = 0;
	while (pNode && i < index)
	{
		pNode = pNode->pNext;
		i++;
	}
	if (!pNode || i>index)
	{
		return false;
	}
	*pValue = pNode->val;
	return true;
}

//删除整个单链表
void ListClear(LinkList pNode)
{
	Node *pHead = pNode->pNext;
	while (pHead != nullptr)
	{
		Node *pNext = pHead->pNext;
		delete pHead;
		pHead = pNext;
	}
	pNode->pNext = NULL;
}



LinkList ListMerge(LinkList head1,LinkList head2)
{
	Node *pa = head1->pNext;
	Node *pb = head2->pNext;
	Node *pret = NULL;
	Node *pc = NULL;
	pret = pa;
	pc = pa;
	while (pa && pb)
	{
		if (pa->val <= pb->val)
		{
			pc->pNext = pa;
			pc = pa;
			pa = pa->pNext;
		}
		else
		{
			pc->pNext = pb;
			pc = pb;
			pb = pb->pNext;
		}
	}
	pc->pNext = pa ? pa : pb;
	free(head2);
	return pret;
}




void MergeTest()
{
	Node *pNode = new Node();
	Node *p1 = new Node();
	p1->val = 1;
	Node *p3 = new Node();
	p3->val = 3;
	pNode->pNext = p1;
	p1->pNext = p3;

	Node *pNode2 = new Node();
	Node *p2 = new Node();
	p2->val = 2;
	Node *p4 = new Node();
	p4->val = 4;

	pNode2->pNext = p2;
	p2->pNext = p4;
	Node *pNodeM = ListMerge(pNode, pNode2);
	ShowList(pNodeM);
}



void ListTest()
{

	MergeTest();


	

}



#endif