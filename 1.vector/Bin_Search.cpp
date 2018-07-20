/*
*bin_search and saddleback_search(������) and interpolation_search(��ֵ����) 
*2018��7��20�� 16:07:06
*/ 
#include"Fib.h"
//��������������[lo,hi)�ڲ���Ԫ��e 
template <typename T>
int binSearch(T* A,T const& e, int lo,int hi){
	while(lo<hi)
	{
		int mi=(lo+hi)>>1;
		(e<A[mi])?hi=mi:lo=mi+1;
	}
	return --lo;
}//�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�ʧ��ʱ������ʧ�ܵ�λ�ã� 

/*saddleback_search(������)
��AΪ��ά������������A[0][0]=0��ÿһ�У��У����ϸ���������һ�㷨��������һ����x>=0,��O(r+s+logn)ʱ���ڣ��Ӹþ������ҳ�������
����ֵΪx��Ԫ��  
saddleback(int A[n][n], int x){
	int i=0;	//�����ԣ���Ч���ҷ�Χʼ��Ϊ���Ͻ��־���A[i,n][0,j] 
	int j=binSearch(A[0][],x,0,n);	//�������ֲ��ң���A�ĵ�0�����ҵ�������x������� 
	while(i<n&&-1<j)
	{
		if(A[i][j]<x)	i++;	//��������ױ����� 
		else if(x<A[i][j])	j--;//���������ұ����� 
		else	{	report(A[i][j]); i++; j--;	}//���У� �ױ����ƣ��ұ����� 
	}
}*/

/*interpolation_search(��ֵ����)
��������Ԫ�ز����������У��ҷ���ĳ�ָ��ʷֲ������÷ֲ����ɣ�����Ŀ����ֵ��ͨ����ֵ���Ƴ����������Ӧ���ȣ��Ӷ�Ѹ����С������Χ��
���裺�����Ҷ���������ֲ���[lo,hi)�ڸ�Ԫ��Ӧ���°��������������� 
 (mi-lo)/(hi-lo)��(Y-A[lo])/(A[hi]-A[lo])
 mi= lo+ (hi-lo)*(Y-A[lo])/(A[hi]-A[lo])
 ���ܣ�ÿ��һ�αȽ�n����n^(1/2)		��O(loglogn) 
*/
#include<iostream>
int main(){
	int a[]={2,4,5,9,9,9,12};
	std::cout<<binSearch(a,9,0,7);
	return 0;
}

