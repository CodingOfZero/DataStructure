/*
*��ӡֵΪx�Ľ�����������(�ǵݹ�������)
*2018��9��14�� 13:25:29
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
				if (p->data == x)//�ҵ�x����ջ��Ԫ��������ջѹ��Outputջ��
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


