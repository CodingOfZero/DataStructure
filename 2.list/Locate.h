/*
*freq初值为0，当在链表中进行一次运算时，令freq+1,
并使此链表中结点保持按访问频度递减的顺序排列，同时最近访问的结点排在同频度的前面;
*2018年8月24日 15:10:32
*/
#include<iostream>
typedef int T;
typedef struct DNode
{
	T data,freq;//访问频度域freq
	struct DNode *pred;
	struct DNode *succ;
}DLinkList;
DLinkList* Locate(DLinkList *&L, int x) {
	DLinkList *p = L->succ,*q;
	while (p&&p->data != x)	//查找值为x的结点
		p = p->succ;
	if (!p)
	{
		std::cout << "不存在值为x的结点" << std::endl;
		exit(0);
	}
	else
	{
		p->freq++;
		p->succ->pred = p->pred;	//将p结点从链表中摘下
		p->pred->succ = p->succ;

		q = p->pred;
		while (q != L&&q->freq <= p->freq)//等于号，使得后面插入时，同频率排第一个
			q = q->pred;
		p->succ = q->succ;	//将p结点插入，一定是排在同频率的第一个
		q->succ->pred = p;
		p->pred = q;
		q->succ = p;
	}
	return p;
}

