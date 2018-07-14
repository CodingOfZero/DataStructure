/*
*Queue_reverse
*2018��7��13�� 20:25:01 
*��������Ԫ����һȡ��������ѹ��ĳһ����ջ��Ȼ������һȡ��ջ�е�Ԫ�ز����β��ԭ���У� 
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
