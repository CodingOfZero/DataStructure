/*
*bubble_sort
*2018年7月20日 17:17:37 
*/
#include<iostream>
void bubblesort_A(int A[],int n){
	bool sorted=false;
	while(!sorted)
	{
		sorted=true;
		for(int i=1;i<n;++i)
		{
			if(A[i-1]>A[i])
			{	
				std::swap(A[i-1],A[i]);
				sorted=false;
			}
		}
		n--;
	}
}
//版本B 
template <typename T>
bool bubble_B(T* A,int lo,int hi){
	bool sorted=true;
	while(++lo<hi)
	{
		if(A[lo-1]>A[lo])
		{
			sorted=false;
			std::swap(A[lo-1],A[lo]);
		}
	}
	return sorted;
}
template <typename T>
void bubblesort_B(T* A,int lo,int hi){
	while(!bubble_B(A ,lo,hi--));
}

//版本C：针对几乎有序的向量，如：乱序元素仅限于A[0,n^(1/2)) 
template <typename T>
bool bubble_C(T* A,int lo,int hi){
	int last=lo;	//最右侧逆序对初始化为[lo-1,lo) 
	while(++lo<hi)
	{
		if(A[lo-1]>A[lo])
		{
			last=lo;	//更新最右侧逆序对位置记录 
			std::swap(A[lo-1],A[lo]);
		}
	}
	return last;//返回最右侧的逆序对位置 
}
template <typename T>
void bubblesort_C(T* A,int lo,int hi){
	while(lo<(hi=bubble_C(A,lo,hi)));	//逐趟做扫描交换，直至全序 
}

int main(){
	int a[]={3,6,19,5,1,0};
	int b[]={1,4,2,6,7,8,9,10};
//	bubblesort_A(a,6);
//	bubblesort_B(a,0,6);
	bubblesort_C(b,0,8);
/*	for(int i=0;i<6;i++)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;*/
	for(int i=0;i<8;i++)
		std::cout<<b[i]<<" ";
	return 0;
}
