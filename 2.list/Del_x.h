/*
*ɾ����ͷ��㵥����������ֵΪx��Ԫ�أ�ɾ��s��t֮��Ԫ�أ�����
*2018��8��19�� 22:55:45
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
void Del_x(LinkList* &L,int e) {//ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1) 
	LinkList *q, *pre = L, *p = L->next;
	while (p!=NULL) {
		if (p->data == e) {		//if(p->data>s&&p->data<t)����ɾ��s��t֮��Ԫ��
			q = p;
			pre->next = p->next;
			free(q);
		}
		else          //����pre��pͬ������
		{
			pre = p;
			p = p->next;
		}
	}
}

