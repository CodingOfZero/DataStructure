/*
*Fibonaccian_search
*2018年7月20日 15:42:20 
*/ 
#include"Fib.h"
//在有序向量区间[lo,hi)内查找元素e 
template <typename T>
int fibSearch(T* A,T const& e, int lo,int hi){
	Fib fib(hi-lo);	//用O(log(hi-lo))时间内创建Fib数列 
	while(lo<hi)
	{
		while((hi-lo)<fib.get())	//get函数返回的是不小于n的最小Fib数 
			fib.prev();
		int mi=lo+fib.get()-1;		//以黄金分隔点作为切分点 
		if(e<A[mi])
			hi=mi;
		else if(A[mi]<e)
			lo=mi+1;
		else
			return mi;
	}
	return -1;
}//有多个命中元素时，不能保证返回秩最大者；失败时，简单返回-1； 
#include<iostream>
int main(){
	int a[]={2,4,5,9,9,9,12};
	std::cout<<fibSearch(a,9,0,7);
	return 0;
}

