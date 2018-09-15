/*
*非空二叉树的宽度（具有结点数最多的一层）
*2018年9月15日 22:50:19
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
//利用层次遍历的方法求出所有结点的层次，并将所有结点和对应的层次放在一个队列中，
//然后通过扫描队列求出各层的结点总数
int BTWidth(BiTree *T) {
	BiTree *p;
	int k,max=0,i=0,n;
	Q.front = Q.rear = -1;
	Q.rear++;
	Q.data[Q.rear] = T;
	Q.level[Q.rear] = 1;
	while (Q.front < Q.rear)
	{
		Q.front++;				//出队
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
	k = 1;//表示从第一层扫描
	while (i <= Q.rear)
	{
		n = 0;//统计第k层结点个数
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



