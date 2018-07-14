/*
*reverse
*2018��7��7�� 22:07:04 
*/ 
#include<iostream>
#include<algorithm>
void reverse(int*A,int lo,int hi){
	while(lo<hi)
		std::swap(A[lo++],A[hi--]);
}
void reverse(int *A,int n){
	reverse(A,0,n-1);
}
//�͵��㷨shift(int A[],int n, int k),��O(n)ʱ���ڽ�����A[0,n)�е�Ԫ������ѭ������kλ
//ǰ׺ΪL��׺ΪR  ������ΪL+R   ѭ�����ƺ�Ϊ R+L    R+L=(L'+R')'  
int shift_L(int A[],int n, int k){
	k%=n;	//ȷ��k<=n 
	reverse(A,k);
	reverse(A+k,n-k);
	reverse(A,n);
} //O(n)
int main(){
	int t[]={1,2,3,4,5,6};
	shift_L(t,6,2);
	for(int i=0;i<6;i++)
		std::cout<<t[i];
}
