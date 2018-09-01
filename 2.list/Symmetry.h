/*
*判断循环双链表是否对称
*2018年8月24日 14:48:06
*/
#include<iostream>
typedef int T;
typedef struct DNode
{
	T data;
	struct DNode *pred;
	struct DNode *succ;
}DLinkList;
//p从左向右扫描，q从右向左扫描，直到它们指向同一结点（奇数时，p=q,偶数时，p->succ=q或q->pred=p）
int Symmetry(DLinkList *L) {
	DLinkList *p = L->succ, *q = L->pred;
	while (p != q&&p->succ != q)
	{
		if (p->data == q->data)//所指结点值相同则继续比较
		{
			p = p->succ;
			q = q->pred;
		}
		else
			return 0;
	}
	return 1;
}

