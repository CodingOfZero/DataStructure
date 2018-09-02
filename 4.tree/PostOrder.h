/*
*二叉树后序非递归遍历
*2018年9月2日 22:08:17
*/
#include<iostream>
#include<stack>
using std::stack;
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
void PostOrder(BiTree *T) {
	BiTree *r=NULL, *p=T;//r指向最近访问过的结点
	stack<BiTree*> s;
	while (p || !s.empty())//走到最左边
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			if (p->rchild&&p->rchild != r)//如果右子树存在，且未被访问过
			{
				p = p->rchild;
				s.push(p);
				p = p->lchild;
			}
			else//否则，弹出结点并访问
			{
				r = s.top();	//记录最近访问过的结点
				std::cout << r->data;
				s.pop();
				p = NULL;//结点访问完后，重置p指针
			}
		}
	}
}

