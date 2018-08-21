/*
*��������
*2018��8��21�� 21:29:08
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
//ͷ�巨��������͵�����	ʱ�临�Ӷ�O(n)
LinkList* List_reverse1(LinkList* L) {
	LinkList *p, *r;//pΪ����ָ�룬rΪp�ĺ�̣���ֹ����
	p = L->next;	//�ӵ�һ��Ԫ�ؽ�㿪ʼ
	L->next = NULL;	//�Ƚ�ͷ���L��next����ΪNULL
	while (p != NULL) 
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p=r;
	}
	return L;
}
//ͨ������ָ�룬ʵ������	ʱ�临�Ӷ�O(n)
LinkList* List_reverse2(LinkList* L) {
	LinkList *pre, *p = L->next, *r = p->next;
	p->next = NULL;		//�����һ�����
	while (r != NULL)
	{
		pre = p;		//���α���
		p = r;
		r = r->next;
		p->next = pre;	//ָ�뷴ת
	}
	L->next = p;		//�������һ�����
	return L;
}

