/*
*���������������
*2018��8��23�� 20:40:05
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
//������
int Length(LinkList *L) {
	int len = 0;
	while (L->next != NULL) {
		len++;
		L = L->next;
	}
	return len;
}
LinkList* Find_Public_Node(LinkList *str1, LinkList *str2) {
	int str1_L = Length(str1), str2_L = Length(str2);
	LinkList *p,*q;
	for (p = str1; str1_L > str2_L; str1_L--)//��str1_L > str2_L ָ��ָ���str1_L-str2_L+1����㣬����forֻ��ִ��һ��
		p = p->next;
	for (q = str2; str2_L > str1_L; str2_L--)
		q = q->next;
	while (p->next != NULL&&p->next != q->next)
	{
		p = p->next;
		q = q->next;
	}
	return p->next;
}
