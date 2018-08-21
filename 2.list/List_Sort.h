/*
*单链表元素递增有序
*2018年8月21日 21:48:08
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
//实现单链表递增有序  时间复杂度O(n^2)
void Sort(LinkList *&L) {
	LinkList *p = L->next, *r = p->next,*pre;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = r->next;	//保存*p的后继结点指针
		pre = L;
		while ((pre->next != NULL) && (pre->next->data < p->data))	//找到插入*p的前驱结点*pre
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;	//扫描原单链表中剩下的结点
	}
}
