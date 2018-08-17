/*
*删除顺序表中值为x的元素（可能不唯一），删除s到t之间元素，非有序表
*2018年8月17日 23:50:07
*/
#include<iostream>
//方法一：用k记录表中不等于x的个数，边扫描边统计k，并将不等于k的元素向前放置k位置上,表长为k;
template<typename T>
void Del_x_1(T* A,int &n,T e) {
	int k = 0;
	for(int i=0;i<n;i++)
		if (A[i] != e) 
			A[k++] = A[i];
	n = k;
}
//方法二：用k记录表中等于x的个数，边扫描边统计k，并将不等于k的元素前移k个位置，表长为n-k
template<typename T>
void Del_x_2(T* A, int &n, T e) {
	int k = 0, i = 0;
	for (; i < n; i++) {
		if (A[i] == e)
			k++;
		else
			A[i - k] = A[i];
	}
	n = n - k;
}
//删除s到t之间的元素,用k记录下元素值在s到t之间元素的个数，若其值不在范围之内，则前移k个位置
template<typename T>
bool Del_s_2(T* A, int &n, T s, T t) {
	int k = 0, i = 0;
	if (s >= t)return false;
	for (; i < n; i++) {
		if (A[i] >= s&&A[i] <= t)//与删除x的版本2只有判别条件不同
			k++;
		else
			A[i - k] = A[i];
	}
	n = n - k;
	return true;
}
int main() {
	int a[] = { 3,5,6,7,13,7,9,7,4,6};
	int n = 10;
	//Del(a, n, 6);
	//Del_x_2(a, n, 7);
	Del_s_2(a, n, 7, 13);
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
}
