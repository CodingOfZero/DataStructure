/*
*freq��ֵΪ0�����������н���һ������ʱ����freq+1,
��ʹ�������н�㱣�ְ�����Ƶ�ȵݼ���˳�����У�ͬʱ������ʵĽ������ͬƵ�ȵ�ǰ��;
*2018��8��24�� 15:10:32
*/
#include<iostream>
typedef int T;
typedef struct DNode
{
	T data,freq;//����Ƶ����freq
	struct DNode *pred;
	struct DNode *succ;
}DLinkList;
DLinkList* Locate(DLinkList *&L, int x) {
	DLinkList *p = L->succ,*q;
	while (p&&p->data != x)	//����ֵΪx�Ľ��
		p = p->succ;
	if (!p)
	{
		std::cout << "������ֵΪx�Ľ��" << std::endl;
		exit(0);
	}
	else
	{
		p->freq++;
		p->succ->pred = p->pred;	//��p����������ժ��
		p->pred->succ = p->succ;

		q = p->pred;
		while (q != L&&q->freq <= p->freq)//���ںţ�ʹ�ú������ʱ��ͬƵ���ŵ�һ��
			q = q->pred;
		p->succ = q->succ;	//��p�����룬һ��������ͬƵ�ʵĵ�һ��
		q->succ->pred = p;
		p->pred = q;
		q->succ = p;
	}
	return p;
}

