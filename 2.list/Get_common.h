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
//元素值不等，值小的指针往后移
LinkList* get_common(LinkList* &A, LinkList* &B) {
	LinkList* C = (LNode*)malloc(sizeof(LNode));
	C->next = NULL;
	LinkList *p = A->next, *q = B->next;
	LinkList *s;
	LinkList *r = C; //r始终指向C的尾结点
	while (p != NULL&&q != NULL)
	{
		if (p->data < q->data)
			p = p->next;
		else if (q->data < p->data)
			q = q->next;
		else
		{
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
	}
	r->next = NULL;
	return C;
}

