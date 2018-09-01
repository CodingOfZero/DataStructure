/*
*�ж�ѭ��˫�����Ƿ�Գ�
*2018��8��24�� 14:48:06
*/
#include<iostream>
typedef int T;
typedef struct DNode
{
	T data;
	struct DNode *pred;
	struct DNode *succ;
}DLinkList;
//p��������ɨ�裬q��������ɨ�裬ֱ������ָ��ͬһ��㣨����ʱ��p=q,ż��ʱ��p->succ=q��q->pred=p��
int Symmetry(DLinkList *L) {
	DLinkList *p = L->succ, *q = L->pred;
	while (p != q&&p->succ != q)
	{
		if (p->data == q->data)//��ָ���ֵ��ͬ������Ƚ�
		{
			p = p->succ;
			q = q->pred;
		}
		else
			return 0;
	}
	return 1;
}

