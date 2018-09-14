/*
*打印值为x的结点的所有祖先(非递归后序遍历)
*2018年9月14日 13:25:29
*/
#include<iostream>
#include<stack>
using std::stack;
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
stack<BiTree *> Search(BiTree *T,int x) {
	BiTree *r=NULL,*p=T;
	stack<BiTree *> S,Output;
	while (p || !S.empty()) {
		if (p)
		{
			S.push(p);
			p = p->lchild;
		}
		else {
			p = S.top();
			if (p->rchild&&p->rchild != r)
			{
				p = p->rchild;
				S.push(p);
				p = p->lchild;
			}
			else
			{
				p = S.top(); S.pop();
				if (p->data == x)//找到x，将栈中元素依次退栈压入Output栈中
				{
					while (!S.empty())
					{
						Output.push(S.top());
						S.pop();
					}
				}
				r = p;
				p = NULL;
			}
		}
	}
	return Output;
}


