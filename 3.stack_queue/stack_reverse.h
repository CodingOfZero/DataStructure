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
