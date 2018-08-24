/*
*反复找出最小值结点输出后删除，直到单链表为空为止;
*2018年8月24日 11:41:03
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
void Del_All(LinkList *&L) {
	LinkList *p, *pre, *minp, *minpre;
	while (L->next != L) //表不空，循环
	{
		p = L->next, pre = L;
		minp = p; minpre = pre;
		while (p != L)	//循环一趟，查找最小值结点
		{
			if (p->data < minp->data)
			{
				minp = p;
				minpre = pre;
			}
			pre = p;
			p = p->next;
		}
		std::cout << minp->data;
		minpre->next = minp->next;
		free(minp);
	}
	free(L);
}
