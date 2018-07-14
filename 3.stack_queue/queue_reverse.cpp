/*
*Queue_reverse
*2018年7月13日 20:25:01 
*将队列中元素逐一取出并依次压入某一辅助栈，然后再逐一取出栈中的元素并依次插回原队列； 
*/
#include<iostream>
#include<stack>
#include<queue>
template<typename T>
void queue_reverse(std::queue<T> &t){
	std::stack<T> s;
	while(!t.empty())
	{
		s.push(t.front());
		t.pop();
	}
	while(!s.empty())
	{
		t.push(s.top());
		s.pop();
	}
} 
int main(){
	std::queue<int> t;
	int tmp;
	while(std::cin>>tmp)
	{
		t.push(tmp);
	}

	queue_reverse(t);
	
	while(!t.empty())
	{
		std::cout<<t.front();
		t.pop();	
	}	
	return 0;	
}
