/*
*查找链表倒数第k个位置上的结点(k为正整数);
*2018年8月24日 13:09:55
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
int Search_k(LinkList *L,int k) {
	LinkList *p=L->next, *q=L->next;
	int count = 0;
	while (p != NULL)	//遍历链表直到最后一个结点
	{
		if (count < k) count++;//计数，若count<k只移动p
		else
			q = q->next;
		p = p->next;		//p、q同步移动
	}
	if (count < k)
		return 0;
	else
	{
		std::cout << q->data;
		return 1;
	}
}
