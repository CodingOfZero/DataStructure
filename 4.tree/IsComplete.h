/*
*判断二叉树是否为完全二叉树
*2018年9月7日 23:00:06
*/
#include<iostream>
#include<queue>
using std::queue;
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
bool IsComplete(BiTree *T) {
	if (!T)
		return true;
	queue<BiTree*> Q;
	BiTree *p;
	Q.push(T);
	while (!Q.empty()) {
		p = Q.front();	Q.pop();
		if (p)
		{
			Q.push(p->lchild);
			Q.push(p->rchild);
		}
		else							//结点为空，检测其后是否有非空结点
		{
			while (!Q.empty())
			{
				p = Q.front(); Q.pop();
				if (p)					//结点非空，则二叉树为非完全二叉树
					return false;
			}
		}
	
	
	}
	return true;
}
