/*
*����������ǵݹ����
*2018��9��2�� 22:08:17
*/
#include<iostream>
#include<stack>
using std::stack;
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
void PostOrder(BiTree *T) {
	BiTree *r=NULL, *p=T;//rָ��������ʹ��Ľ��
	stack<BiTree*> s;
	while (p || !s.empty())//�ߵ������
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			if (p->rchild&&p->rchild != r)//������������ڣ���δ�����ʹ�
			{
				p = p->rchild;
				s.push(p);
				p = p->lchild;
			}
			else//���򣬵�����㲢����
			{
				r = s.top();	//��¼������ʹ��Ľ��
				std::cout << r->data;
				s.pop();
				p = NULL;//�������������pָ��
			}
		}
	}
}

