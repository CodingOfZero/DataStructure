/*
*ջ��ϴ
*2018��7��13�� 21:23:21 
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
	
	for(int i=n;i!=0;--i) 	//Ĭ��ջA=<1��2��3��4��5��...] 
	{
		a.push(i);
	}
	for(int i=n;i!=0;--i)	//�ж��Ƿ�Ϊջ��ϴ������
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
