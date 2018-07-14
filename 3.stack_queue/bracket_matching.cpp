/*
*Bracket_matching
*2018Äê7ÔÂ11ÈÕ 21:17:35 
*/
#include<iostream>
#include<stack>
#include<vector>
bool paren(const std::vector<char> exp){
	std::stack<char> s;
	for(int i=0;i<exp.size();i++)
	{
		switch(exp[i])
		{
			case'(':case'[':case'{':
				s.push(exp[i]);
				break;
			case')':
				if(s.empty()||('('!=s.top()))
					return false;
				else if('('==s.top())
					s.pop();
					break;
			case']':
			if(s.empty()||('['!=s.top()))
				return false;
			else if('['==s.top())
				s.pop();
				break;
			case'}':
			if(s.empty()||('{'!=s.top()))
				return false;
			else if('{'==s.top())
				s.pop();
				break;
			default: break;
		}
		
	}
	return s.empty();
}

int main(){
//	char v[]={'3','(','5','+'};
	std::vector<char> v;
	char c;
	while(std::cin>>c)
		v.push_back(c);
	
	if(paren(v))
		std::cout<<"match";
	else
		std::cout<<"No_match";
}
