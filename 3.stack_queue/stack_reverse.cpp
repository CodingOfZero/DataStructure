/*
*Stack_reverse
*2018年7月13日 20:01:33
*将栈中元素逐一取出并依次插入某一辅助队列，然后再逐一取出队列中的元素并依次插回原栈； 
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
