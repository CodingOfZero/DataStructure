/*
*��������ÿһ��Ԫ��Ϊx�Ľ�㣬ɾ��ÿһ������Ϊ��������;
*2018��9��12�� 13:37:23
*/
#include<iostream>
#include<queue>
using std::queue;
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
//ɾ����TΪ��������(�˲��ú������)
void DeleteTree(BiTree *T) {
	if (T)
	{
		DeleteTree(T->lchild);
		DeleteTree(T->rchild);
		free(T);
	}
}
//�ò�α��������ҵ�ĳ���ĸ��ڵ�
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
			if (p->lchild)//������Ů�ǿ�
			{
				if (p->lchild->data == x)//ֵΪx��ɾ��������
				{
					DeleteTree(p->lchild);
					p->lchild = NULL;
				}
				else
					Q.push(p->lchild);
			}
			if (p->rchild)//������Ů�ǿ�
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

