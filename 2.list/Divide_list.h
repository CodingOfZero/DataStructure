/*
*设C={a1,b1,a2,b2,...}为线性表，采用带头结点单链表存放，将其拆分为两个线性表使得
A={a1,a2,...an} B={bn,bn-2,...b2,b1}
*2018年8月23日 21:08:40
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
LinkList* DisCreat(LinkList* &A) {
	LinkList* B = (LNode*)malloc(sizeof(LNode));//创建B表头
	B->next = NULL;
	LinkList *p = A->next, *q;
	LinkList *r = A;
	while (p != NULL) 
	{
		r->next = p; r = p;
		p = p->next;
		q = p->next;	//头插后，*p将断链，使用q来记忆*p的后继
		p->next = B->next;
		B->next = p;
		p = q;
	}
	r->next = NULL;//A尾结点的next域置空
	return B;
}
