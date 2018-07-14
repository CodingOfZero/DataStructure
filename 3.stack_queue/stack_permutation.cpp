/*
*ջ��ϴ
*Ӧ�ã��г����� 
*	In this station, A is the entrance for each train and B is the exit. S is the transfer end. All single tracks are one-way, 
*which means that the train can enter the station from A to S, and pull out from S to B. Note that the overtaking is not allowed.
*Because the compartments can reside in S, the order that they pull out at B may differ from that they enter at A.
*However, because of the limited capacity of S, no more that m compartments can reside at S simultaneously.
*	Assume that a train consist of n compartments labeled {1, 2, ��, n}. A dispatcher wants to know whether these compartments can pull out at B in the order of {a1, a2, ��, an} (a sequence). 
*If can, in what order he should operate it?
*Input
	Two lines:
		1st line: two integers n and m;
		2nd line: n integers separated by spaces, which is a permutation of {1, 2, ��, n}. This is a compartment sequence that is to be judged regarding the feasibility.
Output
	If the sequence is feasible, output the sequence. ��Push�� means one compartment goes from A to S,
	while ��pop�� means one compartment goes from S to B. Each operation takes up one line.
	If the sequence is infeasible, output a ��no��.
* 
*2018��7��13�� 21:23:21 
*/
#include<iostream>
#include<stack>
#define Max 16
#include<queue>
using std::stack;using std::cout;using std::cin;using std::endl;
template<typename T>
void stack_reverse(std::stack<T> &s){	//ջ��ת 
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
	bool output[7*Max];			//TrueΪpush������FalseΪpop���� 
	int m,n,t;
	int k;						//��� 
	cin>>n>>m;
	for(int i=n;i!=0;--i) 		//Ĭ��ջA=<1��2��3��4��5��...] 
	{
		a.push(i);
	}
	for(int i=n;i!=0;--i)		//�ж��Ƿ�Ϊջ��ϴ������
	{
		cin>>t;
		b.push(t);
	}
	stack_reverse(b);							//ջ�ķ�ת 
	for(int i=n;i>=0;--i)		
	{										 	//��ջA��ջB��ջ����ͬ��ִ��ȡ��Aջ������Sջ�У�Ȼ���ж�S�Ƿ�ջ����δ����ִ��һ��pop������
		if(!a.empty()&&(a.top()==b.top()))	 	//ʹ��top()��������ȷ����ջ����Ϊ�գ��������ִ��� 
		{
			s.push(a.top());	
			if(s.size()>m)						//��Sջ��ջ��ֱ���˳� 
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
