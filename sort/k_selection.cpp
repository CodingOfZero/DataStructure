/*
*K-Selection
*2018年8月4日 23:26:28
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
