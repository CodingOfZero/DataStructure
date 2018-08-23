/*
*设有两个按元素值递增的线性表，均以单链表形式存储，将其归并为一个按元素递减排列的单链表
*2018年8月23日 21:08:40
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
LinkList* MergeList(LinkList* &La,LinkList* &Lb) {
	LinkList *pa = La->next, *pb = Lb->next;
	LinkList *r;
	La->next = NULL;
	while (pa&&pb) 
	{
		if (pa->data <= pb->data)
		{
			r = pa->next;
			pa->next = La->next;
			La->next = pa;
			pa = r;
		}
		else 
		{
			r = pb->next;
			pb->next = La->next;
			La->next = pb;
			pb = r;
		}
	}
	if (pa)	//通常情况下会剩余一个链表非空，处理剩下部分
		pa = pb;
	while (pb)
	{
		r = pb->next;
		pb->next = La->next;
		La->next = pb;
		pb = r;
	}
	free(Lb);
}
