/*
*������Ԫ�ص�������
*2018��8��21�� 21:48:08
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
//ʵ�ֵ������������  ʱ�临�Ӷ�O(n^2)
void Sort(LinkList *&L) {
	LinkList *p = L->next, *r = p->next,*pre;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = r->next;	//����*p�ĺ�̽��ָ��
		pre = L;
		while ((pre->next != NULL) && (pre->next->data < p->data))	//�ҵ�����*p��ǰ�����*pre
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;	//ɨ��ԭ��������ʣ�µĽ��
	}
}
