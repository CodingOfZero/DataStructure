/*
*利用层次遍历非递归方法求解二叉树的高度
*2018年9月3日 21:44:15
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
	while (front < rear)//队不空，则循环
	{
		p = queue[++front];
		if (p->lchild)
			queue[++rear] = p->lchild;
		if (p->rchild)
			queue[++rear] = p->rchild;
		if (front == last)//处理该层最有结点
		{
			level++;
			last = rear;//last指向下层
		}
	}
	return level;
}
