/*
*��p��q����������Ƚ��(�ǵݹ�������)
*2018��9��15�� 13:41:30
*/
#include<iostream>
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
typedef struct {
	BiTree *t;
	int tag;//tag=0��ʾ����Ů�ѱ����ʣ�tag=1��ʾ����Ů�ѱ�����
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
		if (bt == p) {//�ҵ�p���
			for (int i = 1; i <= top; i++)
			{
				s1[i] = s[i];
				top1 = top;
			}
		}
		if (bt == q)//�ҵ�q��㣬��ջ��Ԫ�ص�������s1��ƥ��
		{
			for (int i = top; i > 0; i--)
				for (int j = top1; j > 0; j--)
					if (s[i].t == s1[j].t)
						return s[i].t;
		}
		while (top != 0 && s[top].tag == 1) {//��ջ
			top--;
		}
		if (top != 0)//���ҷ�֧���±���
		{
			s[top].tag = 1;
			bt = s[top].t->rchild;
		}
	}
	return NULL;//p��q�޹�������
}


