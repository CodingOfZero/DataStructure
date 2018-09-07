/*
*先序遍历序列和中序遍历序列分别存放于两个一维数组A[1,n]和B[1,n]中，编写算法建立该二叉树的二叉链表
*2018年9月7日 22:43:36
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
	if (llen)//递归建立左子树
		root->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;
	if (rlen)//递归建立右子树
		root->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;
	return root;
}
