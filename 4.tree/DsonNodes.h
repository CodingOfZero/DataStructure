/*
*�����������˫��֧�����
*2018��9��12�� 12:54:02
*/
#include<iostream>
#include<queue>
using std::queue;
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
int DsonNodes(BiTree *b) {
	if (b == NULL)
		return 0;
	else if (b->lchild != NULL&&b->rchild != NULL)
		return DsonNodes(b->lchild) + DsonNodes(b->rchild) + 1;
	else
		return DsonNodes(b->lchild) + DsonNodes(b->rchild);
}

