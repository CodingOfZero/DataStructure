/*
*对于树中每一个元素为x的结点，删除每一个以它为根的子树;
*2018年9月12日 13:37:23
*/
#include<iostream>
#include<queue>
using std::queue;
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
//删除以T为根的子树(宜采用后序遍历)
void DeleteTree(BiTree *T) {
	if (T)
	{
		DeleteTree(T->lchild);
		DeleteTree(T->rchild);
		free(T);
	}
}
//用层次遍历易于找到某结点的父节点
void Search(BiTree *T, int x) {
	queue<BiTree*> Q;
	BiTree *p;
	if (T) {
		if (T->data == x)
		{
			DeleteTree(T);
			exit(0);
		}
		Q.push(T);
		while (!Q.empty())
		{
			p = Q.front(); Q.pop();
			if (p->lchild)//若左子女非空
			{
				if (p->lchild->data == x)//值为x则删除左子树
				{
					DeleteTree(p->lchild);
					p->lchild = NULL;
				}
				else
					Q.push(p->lchild);
			}
			if (p->rchild)//若右子女非空
			{
				if (p->rchild->data == x)
				{
					DeleteTree(p->rchild);
					p->rchild = NULL;
				}
				else
					Q.push(p->rchild);
			}
		}
	}
}

