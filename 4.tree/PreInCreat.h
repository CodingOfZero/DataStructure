/*
*����������к�����������зֱ���������һά����A[1,n]��B[1,n]�У���д�㷨�����ö������Ķ�������
*2018��9��7�� 22:43:36
*/
#include<iostream>
#define Maxsize 50
typedef struct BiTNode {
	int data;
	BiTNode *lchild, *rchild;
}BiTree;
BiTree *PreInCreat(int A[], int B[], int l1, int h1, int l2, int h2) {//l1=l2=1,h1=h2=n
	BiTree *root = (BiTree*)malloc(sizeof(BiTree));
	root->data = A[l1];
	int i, llen, rlen;
	for (i = l2; B[i] != root->data; i++);
	llen = i - l2;
	rlen = h2 - i;
	if (llen)//�ݹ齨��������
		root->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;
	if (rlen)//�ݹ齨��������
		root->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;
	return root;
}
