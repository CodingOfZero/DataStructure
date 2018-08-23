/*
*����������Ԫ��ֵ���������Ա����Ե�������ʽ�洢������鲢Ϊһ����Ԫ�صݼ����еĵ�����
*2018��8��23�� 21:08:40
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
LinkList* MergeList(LinkList* &La,LinkList* &Lb) {
	LinkList *pa = La->next, *pb = Lb->next;
	LinkList *r;
	La->next = NULL;
	while (pa&&pb) 
	{
		if (pa->data <= pb->data)
		{
			r = pa->next;
			pa->next = La->next;
			La->next = pa;
			pa = r;
		}
		else 
		{
			r = pb->next;
			pb->next = La->next;
			La->next = pb;
			pb = r;
		}
	}
	if (pa)	//ͨ������»�ʣ��һ������ǿգ�����ʣ�²���
		pa = pb;
	while (pb)
	{
		r = pb->next;
		pb->next = La->next;
		La->next = pb;
		pb = r;
	}
	free(Lb);
}
