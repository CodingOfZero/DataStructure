/*
*两个单链表公共结点
*2018年8月23日 20:40:05
*/
#include<iostream>
typedef int T;
typedef struct LNode
{
	T data;
	struct LNode *next;
}LinkList;
//链表长度
int Length(LinkList *L) {
	int len = 0;
	while (L->next != NULL) {
		len++;
		L = L->next;
	}
	return len;
}
LinkList* Find_Public_Node(LinkList *str1, LinkList *str2) {
	int str1_L = Length(str1), str2_L = Length(str2);
	LinkList *p,*q;
	for (p = str1; str1_L > str2_L; str1_L--)//若str1_L > str2_L 指针指向第str1_L-str2_L+1个结点，两个for只会执行一个
		p = p->next;
	for (q = str2; str2_L > str1_L; str2_L--)
		q = q->next;
	while (p->next != NULL&&p->next != q->next)
	{
		p = p->next;
		q = q->next;
	}
	return p->next;
}
