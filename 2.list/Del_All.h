/*
*�����ҳ���Сֵ��������ɾ����ֱ��������Ϊ��Ϊֹ;
*2018��8��24�� 11:41:03
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
	while (L->next != L) //���գ�ѭ��
	{
		p = L->next, pre = L;
		minp = p; minpre = pre;
		while (p != L)	//ѭ��һ�ˣ�������Сֵ���
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
