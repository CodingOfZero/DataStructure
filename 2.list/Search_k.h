/*
*������������k��λ���ϵĽ��(kΪ������);
*2018��8��24�� 13:09:55
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
int Search_k(LinkList *L,int k) {
	LinkList *p=L->next, *q=L->next;
	int count = 0;
	while (p != NULL)	//��������ֱ�����һ�����
	{
		if (count < k) count++;//��������count<kֻ�ƶ�p
		else
			q = q->next;
		p = p->next;		//p��qͬ���ƶ�
	}
	if (count < k)
		return 0;
	else
	{
		std::cout << q->data;
		return 1;
	}
}
