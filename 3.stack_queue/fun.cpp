/*
*利用栈实现递归函数的非递归计算
	  1									n=0;
Pn(x)=2*x								n=1;
	  2*x*P(n-1)(x)-2*(n-1)*P(n-2)(x);	n>1;
*2018年8月31日 22:21:17
*/
#include<iostream>
#define Maxsize 50
struct Stack {
	int no;
	double val;
}st[Maxsize];
double p(int n, double x) {
	int top = -1, i;
	double fv1 = 1, fv2 = 2 * x;
	for (i = n; i > 1; i--) {//入栈
		st[++top].no = i;
	}
	while (top >= 0)
	{
		st[top].val = 2 * x*fv2 - 2 * (st[top].no - 1)*fv1;
		fv1 = fv2;
		fv2 = st[top].val;
		top--;
	}
	if (n == 0)
		return fv1;
	return fv2;
}


