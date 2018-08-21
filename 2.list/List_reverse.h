/*
*链表逆置
*2018年8月21日 21:29:08
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
//头插法将单链表就地逆置	时间复杂度O(n)
LinkList* List_reverse1(LinkList* L) {
	LinkList *p, *r;//p为工作指针，r为p的后继，防止断链
	p = L->next;	//从第一个元素结点开始
	L->next = NULL;	//先将头结点L的next域置为NULL
	while (p != NULL) 
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p=r;
	}
	return L;
}
//通过调整指针，实现逆置	时间复杂度O(n)
LinkList* List_reverse2(LinkList* L) {
	LinkList *pre, *p = L->next, *r = p->next;
	p->next = NULL;		//处理第一个结点
	while (r != NULL)
	{
		pre = p;		//依次遍历
		p = r;
		r = r->next;
		p->next = pre;	//指针反转
	}
	L->next = p;		//处理最后一个结点
	return L;
}

