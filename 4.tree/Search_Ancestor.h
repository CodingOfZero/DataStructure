/*
*找p和q最近公共祖先结点(非递归后序遍历)
*2018年9月15日 13:41:30
*/
#include<iostream>
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
typedef struct {
	BiTree *t;
	int tag;//tag=0表示左子女已被访问，tag=1表示右子女已被访问
}Stack;
Stack s[], s1[];
BiTree* Search(BiTree *ROOT,BiTree *p,BiTree *q) {
	BiTree *r=NULL,*bt=ROOT;
	int top = 0, top1 = 0;
	while (bt || top>0) {
		while (bt && bt != p && bt != q)
		{
			s[++top].t = bt;
			s[top].tag = 0;
			bt = bt->lchild;
		}
		if (bt == p) {//找到p结点
			for (int i = 1; i <= top; i++)
			{
				s1[i] = s[i];
				top1 = top;
			}
		}
		if (bt == q)//找到q结点，将栈中元素的树结点和s1中匹配
		{
			for (int i = top; i > 0; i--)
				for (int j = top1; j > 0; j--)
					if (s[i].t == s1[j].t)
						return s[i].t;
		}
		while (top != 0 && s[top].tag == 1) {//退栈
			top--;
		}
		if (top != 0)//沿右分支向下遍历
		{
			s[top].tag = 1;
			bt = s[top].t->rchild;
		}
	}
	return NULL;//p和q无公共祖先
}


