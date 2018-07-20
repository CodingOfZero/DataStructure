/*
*bin_search and saddleback_search(马鞍查找) and interpolation_search(插值查找) 
*2018年7月20日 16:07:06
*/ 
#include"Fib.h"
//在有序向量区间[lo,hi)内查找元素e 
template <typename T>
int binSearch(T* A,T const& e, int lo,int hi){
	while(lo<hi)
	{
		int mi=(lo+hi)>>1;
		(e<A[mi])?hi=mi:lo=mi+1;
	}
	return --lo;
}//有多个命中元素时，总能保证返回秩最大者；失败时，返回失败的位置； 

/*saddleback_search(马鞍查找)
设A为二维向量整数矩阵，A[0][0]=0且每一行（列）都严格递增。设计一算法，对于任一整数x>=0,在O(r+s+logn)时间内，从该矩阵中找出并报告
所有值为x的元素  
saddleback(int A[n][n], int x){
	int i=0;	//不变性：有效查找范围始终为左上角字矩形A[i,n][0,j] 
	int j=binSearch(A[0][],x,0,n);	//借助二分查找，从A的第0行中找到不大于x的最大者 
	while(i<n&&-1<j)
	{
		if(A[i][j]<x)	i++;	//矩形区域底边上移 
		else if(x<A[i][j])	j--;//矩形区域右边左移 
		else	{	report(A[i][j]); i++; j--;	}//命中， 底边上移，右边左移 
	}
}*/

/*interpolation_search(插值查找)
有序向量元素不仅单调排列，且服从某种概率分布。利用分布规律，根据目标数值，通过插值估计出其大致所对应的秩，从而迅速缩小搜索范围。
假设：均匀且独立的随机分布，[lo,hi)内各元素应大致按照线性趋势增长 
 (mi-lo)/(hi-lo)≈(Y-A[lo])/(A[hi]-A[lo])
 mi= lo+ (hi-lo)*(Y-A[lo])/(A[hi]-A[lo])
 性能：每经一次比较n缩至n^(1/2)		故O(loglogn) 
*/
#include<iostream>
int main(){
	int a[]={2,4,5,9,9,9,12};
	std::cout<<binSearch(a,9,0,7);
	return 0;
}

