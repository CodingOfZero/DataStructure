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
//Ԫ��ֵ���ȣ�ֵС��ָ��������
LinkList* get_common(LinkList* &A, LinkList* &B) {
	LinkList* C = (LNode*)malloc(sizeof(LNode));
	C->next = NULL;
	LinkList *p = A->next, *q = B->next;
	LinkList *s;
	LinkList *r = C; //rʼ��ָ��C��β���
	while (p != NULL&&q != NULL)
	{
		if (p->data < q->data)
			p = p->next;
		else if (q->data < p->data)
			q = q->next;
		else
		{
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
	}
	r->next = NULL;
	return C;
}

