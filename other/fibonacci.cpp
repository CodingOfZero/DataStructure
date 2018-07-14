/**/
#include<iostream>
#include"Fib.h"
__int64 Fib_I(int n){
	__int64 f=1,g=0;
	while(0<n--){
		g+=f;
		f=g-f;
	}
	return g;
}
int main(){
	int n;
	std::cin>>n;
/*	int i=Fib_I(n);
	std::cout<<i;*/
	std::cout<<Fib(n).prev()<<" "<<Fib(n).get()<<" "<<Fib(n).next()<<std::endl; 
}
