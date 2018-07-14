/*
*Binary_conversion
*2018Äê7ÔÂ11ÈÕ 20:05:14 
*/
#include<iostream>
#include<stack>
void convert(std::stack<char>& s , __int64 n , int base){
	static char a[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while(n>0)
	{
		int m= (int)(n % base);
		s.push(a[m]);
		n/=base;
	}
}
int main(){
	std::stack<char> t;
	__int64 n;
	int base;
	std::cin>>n>>base;
	convert(t,n,base);
	while(!t.empty())
	{
		char value=t.top();
		t.pop();
		std::cout<<value;
	}
}
