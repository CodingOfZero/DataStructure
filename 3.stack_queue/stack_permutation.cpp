/*
*栈混洗
*2018年7月13日 21:23:21 
*/
#include<iostream>
#include<stack>
#define Max 16
#include"stack_reverse.h"
using std::stack;using std::cout;using std::cin;
int main(){
	stack<int> a,s,b;
	bool output[7*Max];
	int m,n,t;
	int k;
	cin>>n>>m;
	
	for(int i=n;i!=0;--i) 	//默认栈A=<1，2，3，4，5，...] 
	{
		a.push(i);
	}
	for(int i=n;i!=0;--i)	//判断是否为栈混洗的序列
	{
		cin>>t;
		b.push(t);
	}
	stack_reverse(b);
	for(int i=n;i!=0;--i)
	{
		if(a.top()==b.top())
		{
			b.pop();
			s.push(a.top());
			a.pop();
			output[k++]=false;
			output[k++]=true;
			if(s.size()>m)
			{
				cout<<"No";
				return 0;
			}
		}else
		{
			s.push(a.top());
			a.pop();
			output[k++]=true;
			if(s.size()>m)
			{
				cout<<"No";
				return 0;
			}
		}	
		
	}

	return 0;
}
