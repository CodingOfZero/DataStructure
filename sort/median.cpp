/*
*median
*2018年8月4日 17:22:07
*/
#include<iostream>
#include<vector>
using std::vector;
//中位数蛮力版：仅适用于max(n1,n2)较小的情况 O(n1+n2)
//子向量S1[lo1,lo1+n1)和S2[lo2,lo2+n2)分别有序，数据项可能重复
int trivialMedian(vector<int> &S1,int lo1,int n1,vector<int> &S2,int lo2,int n2) {
	vector<int> S;
	int hi1 = lo1 + n1, hi2 = lo2 + n2;
	while ((lo1 < hi1) && (lo2 < hi2))
	{
		if (lo2 == hi2)	break;//防止vector超出范围
		while ((lo1 < hi1) && (S1[lo1] <= S2[lo2]))
			S.push_back(S1[lo1++]);
		if (lo1 == hi1)	break;	//防止vector超出范围
		while ((lo2 < hi2) && (S2[lo2] <= S1[lo1]))
			S.push_back(S2[lo2++]);
	}
	while (lo1 < hi1)
		S.push_back(S1[lo1++]);
	while (lo2 < hi2)
		S.push_back(S2[lo2++]);
	return S[(n1+n2)/2];
}

//等长有序向量归并后中位数	O(logn)
int median(vector<int> &S1, int lo1, vector<int> &S2, int lo2, int n) {
	if (n < 3)	return trivialMedian(S1, lo1, n, S2, lo2, n);
	int mi1 = lo1 + n / 2, mi2 = lo2 + (n-1) / 2;//考查S1的中位数以及S2的逆向中位数
	if (S1[mi1] < S2[mi2])//S1右半 S2左半
		return median(S1, mi1, S2, lo2, n + lo1 - mi1);
	else if (S2[mi2] < S1[mi1])//S1左半 S2右半
		return median(S1, lo1, S2, mi2, n + lo2 - mi2);
	else
		return S1[mi1];
}

//非等长有序向量S1和S2
int median_A(vector<int> &S1, int lo1, int n1, vector<int> &S2, int lo2, int n2) {
	if (n2 < n1) return median_A(S2, lo2, n2, S1, lo1, n1);	//确保n1<=n2
	if (n2 < 6)//递归基：1<=n1<=n2<=5
		return trivialMedian(S1, lo1, n1, S2, lo2, n2);
	if (2 * n1 < n2)//若两个向量长度相差悬殊，则长者的两翼可直接截除
		return median_A(S1, lo1, n1, S2, lo2 + (n2 - n1 - 1) / 2, n1 + 2 - (n2 - n1) % 2);
	int mi1 = lo1 + n1 / 2;
	int mi2a = lo2 + (n1 - 1) / 2;
	int mi2b = lo2 + n2 - 1 - n1 / 2;
	if (S1[mi1] < S2[mi2a])//S1右半 S2左半
		return median_A(S1, mi1, (n1 + 1) / 2, S2, lo2, n2 - n1 / 2);
	if (S2[mi2b] < S1[mi1])//S1左半 S2右半
		return median_A(S1, lo1, n1 / 2 + 1, S2, mi2a, n2 - (n1 - 1) / 2);
	else//S1保留，S2左右同时缩短
		return median_A(S1, lo1, n1, S2, mi2a, n2 - (n1 - 1) / 2 * 2);
}
int main() {
	vector<int> t = { 3,7 };
	vector<int> t1 = { 1,2,3,4 };
	vector<int> t2 = { 1,2,4 };
	vector<int> t3 = { 1,2,3,4,5,6,7 };
//	std::cout << median(t1, 0, t2, 0, 3);
	std::cout << median_A(t, 0, 2, t3, 0, 7);

}

