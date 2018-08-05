/*
*K-Selection
*2018年8月4日 23:26:28
*算法主要计算流程
select(A,k)
输入：规模为n的无序序列A，秩K>=0
输出：A所对应有序序列中秩为k的元素
{
	if(n==|A|<Q) return trivialSelect(A,k);//递归基：序列规模不大时直接使用蛮力算法
	将A均匀地划分为n/Q个子序列，各含Q个元素;//Q为5
	各子序列分别排序，计算中位数，并将这些中位数组成一个序列;//可采用任何排序算法
	通过递归调用select()，计算出中位数序列的中位数，记做M;
	根据其相对于M的大小，将A中元素分为三个子集：L(小于),E(相等),G(大于);
	if(|L|>=k) return select(L,k);
	else if(|L|+|E|>=k) return M;
	else return select(G,k-|L|-|E|);
}//最坏情况下依然为O(n)
*/
#include<iostream>
#include<vector>
using std::vector;
//基于快速划分的k选取算法O(n*2)
int quickSelect(vector<int> &A, int k) {
	int pivot;
	for (int lo = 0, hi = A.size() - 1; lo < hi;) {
		int i = lo, j = hi;
		pivot = A[lo];
		while (i < j) {
			while ((i < j) && (pivot <= A[j]))j--;
			A[i] = A[j];
			while ((i < j) && (A[i] <= pivot))i++;
			A[j] = A[i];
		}
		A[i] = pivot;
		if (k <= i)hi = i - 1;
		if (i <= k)lo = i + 1;
	}
	return pivot;
}
int main() {
	vector<int>t = { 2,5,7,8,34,7,8,9 };
	std::cout << quickSelect(t, 8);
}
