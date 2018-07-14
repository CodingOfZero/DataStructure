/*
*Stack_reverse
*2018��7��13�� 20:01:33
*��ջ��Ԫ����һȡ�������β���ĳһ�������У�Ȼ������һȡ�������е�Ԫ�ز����β��ԭջ�� 
*/
#include<iostream>
#include<stack>
#include<queue>
template<typename T>
void stack_reverse(std::stack<T> &s){
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
	std::stack<int> s;
	int tmp;
	while(std::cin>>tmp)
	{
		s.push(tmp);
	}

	stack_reverse(s);
	
	while(!s.empty())
	{
		std::cout<<s.top();
		s.pop();	
	}	
	return 0;	
}
