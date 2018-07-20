/*
*Fibonaccian_search
*2018��7��20�� 15:42:20 
*/ 
#include"Fib.h"
//��������������[lo,hi)�ڲ���Ԫ��e 
template <typename T>
int fibSearch(T* A,T const& e, int lo,int hi){
	Fib fib(hi-lo);	//��O(log(hi-lo))ʱ���ڴ���Fib���� 
	while(lo<hi)
	{
		while((hi-lo)<fib.get())	//get�������ص��ǲ�С��n����СFib�� 
			fib.prev();
		int mi=lo+fib.get()-1;		//�Իƽ�ָ�����Ϊ�зֵ� 
		if(e<A[mi])
			hi=mi;
		else if(A[mi]<e)
			lo=mi+1;
		else
			return mi;
	}
	return -1;
}//�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�ʧ��ʱ���򵥷���-1�� 
#include<iostream>
int main(){
	int a[]={2,4,5,9,9,9,12};
	std::cout<<fibSearch(a,9,0,7);
	return 0;
}

