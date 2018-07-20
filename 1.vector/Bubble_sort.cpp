/*
*bubble_sort
*2018��7��20�� 17:17:37 
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
//�汾B 
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

//�汾C����Լ���������������磺����Ԫ�ؽ�����A[0,n^(1/2)) 
template <typename T>
bool bubble_C(T* A,int lo,int hi){
	int last=lo;	//���Ҳ�����Գ�ʼ��Ϊ[lo-1,lo) 
	while(++lo<hi)
	{
		if(A[lo-1]>A[lo])
		{
			last=lo;	//�������Ҳ������λ�ü�¼ 
			std::swap(A[lo-1],A[lo]);
		}
	}
	return last;//�������Ҳ�������λ�� 
}
template <typename T>
void bubblesort_C(T* A,int lo,int hi){
	while(lo<(hi=bubble_C(A,lo,hi)));	//������ɨ�轻����ֱ��ȫ�� 
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
