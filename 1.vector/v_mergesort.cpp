/*
*向量的归并排序
*计算量主要消耗于有序子向量的归并操作，而子向量的划分却几乎不费时间，与快排相反； 
*2018年7月21日 15:53:34
*/
#include<vector>
#include<iostream>
using std::vector;
template<typename T>
void v_merge(T *s,int lo,int mi, int hi);

template<typename T>
void v_mergesort(T *s, int lo, int hi) {
	if (hi - lo<2)	return;		//单元素自然有序
	int mi = (hi + lo) >> 1;
	v_mergesort(s, lo, mi);	//前半段
	v_mergesort(s, mi, hi);	//后半段
	v_merge(s,lo, mi, hi);	//合并
}
template<typename T>
void v_merge(T *s,int lo, int mi, int hi) {//各自有序的子向量[lo,mi)和[mi,hi)
	T *A = s+lo;
	int lb = mi - lo;  T *B = new T[lb];	//前子向量
	for (int i = 0; i<lb; B[i] = A[i++]);	//复制前子向量
	int lc = hi - mi;  T *C = s+mi;			//后子向量C[0,lc]=s[mi,hi)
	for (int i = 0, j = 0, k = 0; j<lb;)
	{														//若将B[j] <= C[k]变为B[j] < C[k]，循环体内处理语句均失效，进入死循环；
		if ((lc <= k) || (B[j] <= C[k]))	A[i++] = B[j++];//只要前者不大于后者（包含二者相等），都会优先转移前者；
		if ((k < lc) && (C[k] < B[j]))	A[i++] = C[k++];	//唯有前者严格大于后者，才会将后者转移至A[i++]以此保证稳定性；
	}
	delete[]B;
}
int main() {
	int t[] = { 23,3,4,5,2,1,6,7 };
	v_mergesort(t, 0, 8);
/*	for (auto a : t)
		std::cout << a<<" ";*/
	for(int i=0;i<8;++i)
		std::cout<<t[i]<<" ";
	return 0;
}
