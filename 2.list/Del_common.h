/* 
* �õ�������m����������|data|<=n,����㷨�Ծ���ֵ��ȵĽ�㣬
*��������һ�γ��ֵĽ���ɾ���������ֵ��ȵĽ�� 
*2018��8��24�� 14:09:25 
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
//ʱ�临�Ӷ�ΪO(m)���ռ临�Ӷ�ΪO(n)
void func(LinkList *&L,int n) {
	LinkList *p = L, *r;
	int *q,m;
	q = (int*)malloc(sizeof(int)*(n + 1));//����n+1��λ�õĸ����ռ�
	for (int i = 0; i < n + 1; i++)//����Ԫ�س�ֵΪ0
		*(q + i) = 0;
	while (p->next!=NULL)
	{
		m = p->next->data > 0 ? p->next->data : -p->next->data;
		if (*(q + m) == 0)	//�жϸý���data�Ƿ��ѳ��ֹ�
		{
			*(q + m) = 1;
			p = p->next;
		}
		else				//�ظ�����
		{
			r = p->next;
			p->next = r->next;
			free(r);
		}
	}
	free(q);
}


