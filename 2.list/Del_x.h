/*
*删除带头结点单链表中所有值为x的元素，删除s到t之间元素，无序
*2018年8月19日 22:55:45
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
void Del_x(LinkList* &L,int e) {//时间复杂度O(n) 空间复杂度O(1) 
	LinkList *q, *pre = L, *p = L->next;
	while (p!=NULL) {
		if (p->data == e) {		//if(p->data>s&&p->data<t)即可删除s到t之间元素
			q = p;
			pre->next = p->next;
			free(q);
		}
		else          //否则pre和p同步后移
		{
			pre = p;
			p = p->next;
		}
	}
}

