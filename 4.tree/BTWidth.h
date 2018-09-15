/*
*�ǿն������Ŀ�ȣ����н��������һ�㣩
*2018��9��15�� 22:50:19
*/
#include<iostream>
#define Maxsize 50
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
typedef struct {
	BiTree *data[Maxsize];
	int level[Maxsize];
	int front, rear;
}Queue;
Queue Q;
//���ò�α����ķ���������н��Ĳ�Σ��������н��Ͷ�Ӧ�Ĳ�η���һ�������У�
//Ȼ��ͨ��ɨ������������Ľ������
int BTWidth(BiTree *T) {
	BiTree *p;
	int k,max=0,i=0,n;
	Q.front = Q.rear = -1;
	Q.rear++;
	Q.data[Q.rear] = T;
	Q.level[Q.rear] = 1;
	while (Q.front < Q.rear)
	{
		Q.front++;				//����
		p = Q.data[Q.front];
		k = Q.level[Q.front];
		if (p->lchild != NULL)
		{
			Q.rear++;
			Q.data[Q.rear] = p->lchild;
			Q.level[Q.rear] = k + 1;
		}
		if (p->rchild != NULL)
		{
			Q.rear++;
			Q.data[Q.rear] = p->rchild;
			Q.level[Q.rear] = k + 1;
		}
	}
	k = 1;//��ʾ�ӵ�һ��ɨ��
	while (i <= Q.rear)
	{
		n = 0;//ͳ�Ƶ�k�������
		while (i <= Q.rear&&Q.level[i] == k)
		{
			n++;
			i++;
		}
		k = Q.level[i];
		if (n > max) max = n;
	}
	return max;
}



