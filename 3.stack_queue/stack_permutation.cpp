/*
*栈混洗
*应用：列车调度 
*	In this station, A is the entrance for each train and B is the exit. S is the transfer end. All single tracks are one-way, 
*which means that the train can enter the station from A to S, and pull out from S to B. Note that the overtaking is not allowed.
*Because the compartments can reside in S, the order that they pull out at B may differ from that they enter at A.
*However, because of the limited capacity of S, no more that m compartments can reside at S simultaneously.
*	Assume that a train consist of n compartments labeled {1, 2, …, n}. A dispatcher wants to know whether these compartments can pull out at B in the order of {a1, a2, …, an} (a sequence). 
*If can, in what order he should operate it?
*Input
	Two lines:
		1st line: two integers n and m;
		2nd line: n integers separated by spaces, which is a permutation of {1, 2, …, n}. This is a compartment sequence that is to be judged regarding the feasibility.
Output
	If the sequence is feasible, output the sequence. “Push” means one compartment goes from A to S,
	while “pop” means one compartment goes from S to B. Each operation takes up one line.
	If the sequence is infeasible, output a “no”.
* 
*2018年7月13日 21:23:21 
*/
#include<iostream>
#include<stack>
#define Max 16
#include<queue>
using std::stack;using std::cout;using std::cin;using std::endl;
template<typename T>
void stack_reverse(std::stack<T> &s){	//栈翻转 
	std::queue<T> t;
	while(!s.empty())
	{
		t.push(s.top());
		s.pop();
	}
	while(!t.empty())
	{
		s.push(t.front());
		t.pop();
	}
} 
int main(){
	stack<int> a,s,b;
	bool output[7*Max];			//True为push操作，False为pop操作 
	int m,n,t;
	int k;						//输出 
	cin>>n>>m;
	for(int i=n;i!=0;--i) 		//默认栈A=<1，2，3，4，5，...] 
	{
		a.push(i);
	}
	for(int i=n;i!=0;--i)		//判断是否为栈混洗的序列
	{
		cin>>t;
		b.push(t);
	}
	stack_reverse(b);				//栈的翻转 
	for(int i=n;i>=0;--i)		
	{						//若栈A和栈B的栈顶相同，执行取出A栈顶放入S栈中，然后判断S是否爆栈，若未，则执行一次pop操作；
		if(!a.empty()&&(a.top()==b.top()))	//使用top()函数必须确定该栈不能为空，否则会出现错误； 
		{
			s.push(a.top());	
			if(s.size()>m)			//若S栈爆栈，直接退出 
			{
				cout<<"No";
				return 0;
			}
			a.pop();
			b.pop();
			s.pop();
			output[k++]=true;
			output[k++]=false;

		}else if(!s.empty()&&(s.top()==b.top()))	 
		{
			output[k++]=false;
			s.pop();
		}else	
		{
			s.push(a.top());
			a.pop();
			output[k++]=true;
			if(a.empty()||s.size()>m)
			{
				cout<<"No";
				return 0;
			}
		}		
	}
	for(int i=0;i<k;i++)
	{
		if(output[i])
			cout<<"push"<<endl;
		else
			cout<<"pop"<<endl;
	}
	return 0;
}
