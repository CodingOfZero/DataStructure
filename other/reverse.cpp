/*
*reverse
*2018年7月7日 22:07:04 
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
//就地算法shift(int A[],int n, int k),在O(n)时间内将数组A[0,n)中的元素整体循环左移k位
//前缀为L后缀为R  总序列为L+R   循环左移后为 R+L    R+L=(L'+R')'  
int shift_L(int A[],int n, int k){
	k%=n;	//确保k<=n 
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
