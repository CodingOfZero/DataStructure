/*
*sum of number
*2018��7��7�� 21:16:32 
*/ 
#include<iostream>

int sum(int A[],int n){  //������ͣ������棩O(n) 
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=A[i];
	return sum;
} 

int sum1(int A[],int n){	//���Եݹ�� 
	if(1>n)
		return 0;
	else
		return sum1(A,n-1)+A[n-1];
}//o(1)*�ݹ���� = O(1)*(n-1)=O(n) 

int sum2(int A[],int lo,int hi){ //���ֵݹ�� 
	if(lo==hi)
		return A[lo];
	else{
		int mi=(lo+hi)>>1;	
		return sum2(A, lo, mi)+sum2(A,mi+1,hi);
	}	
}//O(hi-lo+1),�������������䳤�� 

int main(){
	int t[]={1,5,6,8,8,8,94,3};
	std::cout<<sum(t,8)<<std::endl;
	std::cout<<sum1(t,8)<<std::endl;
	std::cout<<sum2(t,0,7)<<std::endl;
	return 0;
}
