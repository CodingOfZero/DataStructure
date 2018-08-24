/* 
* 用单链表保存m个整数，且|data|<=n,设计算法对绝对值相等的结点，
*仅保留第一次出现的结点而删除其余绝对值相等的结点 
*2018年8月24日 14:09:25 
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
//时间复杂度为O(m)，空间复杂度为O(n)
void func(LinkList *&L,int n) {
	LinkList *p = L, *r;
	int *q,m;
	q = (int*)malloc(sizeof(int)*(n + 1));//申请n+1个位置的辅助空间
	for (int i = 0; i < n + 1; i++)//数组元素初值为0
		*(q + i) = 0;
	while (p->next!=NULL)
	{
		m = p->next->data > 0 ? p->next->data : -p->next->data;
		if (*(q + m) == 0)	//判断该结点的data是否已出现过
		{
			*(q + m) = 1;
			p = p->next;
		}
		else				//重复出现
		{
			r = p->next;
			p->next = r->next;
			free(r);
		}
	}
	free(q);
}


