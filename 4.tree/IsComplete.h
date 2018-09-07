/*
*�ж϶������Ƿ�Ϊ��ȫ������
*2018��9��7�� 23:00:06
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
		else							//���Ϊ�գ��������Ƿ��зǿս��
		{
			while (!Q.empty())
			{
				p = Q.front(); Q.pop();
				if (p)					//���ǿգ��������Ϊ����ȫ������
					return false;
			}
		}
	
	
	}
	return true;
}
