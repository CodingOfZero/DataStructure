/*
*��C={a1,b1,a2,b2,...}Ϊ���Ա����ô�ͷ��㵥�����ţ�������Ϊ�������Ա�ʹ��
A={a1,a2,...an} B={bn,bn-2,...b2,b1}
*2018��8��23�� 21:08:40
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
LinkList* DisCreat(LinkList* &A) {
	LinkList* B = (LNode*)malloc(sizeof(LNode));//����B��ͷ
	B->next = NULL;
	LinkList *p = A->next, *q;
	LinkList *r = A;
	while (p != NULL) 
	{
		r->next = p; r = p;
		p = p->next;
		q = p->next;	//ͷ���*p��������ʹ��q������*p�ĺ��
		p->next = B->next;
		B->next = p;
		p = q;
	}
	r->next = NULL;//Aβ����next���ÿ�
	return B;
}
