/*
*���ò�α����ǵݹ鷽�����������ĸ߶�
*2018��9��3�� 21:44:15
*/
#include<iostream>
#define Maxsize 50
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
int Btdepth(BiTree *T) {
	if (!T)
		return 0;
	BiTree* queue[Maxsize];
	int front = -1, rear = -1, level = 0, last = 0;
	queue[++rear] = T;
	BiTree *p;
	while (front < rear)//�Ӳ��գ���ѭ��
	{
		p = queue[++front];
		if (p->lchild)
			queue[++rear] = p->lchild;
		if (p->rchild)
			queue[++rear] = p->rchild;
		if (front == last)//����ò����н��
		{
			level++;
			last = rear;//lastָ���²�
		}
	}
	return level;
}
