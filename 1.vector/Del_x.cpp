/*
*ɾ��˳�����ֵΪx��Ԫ�أ����ܲ�Ψһ����ɾ��s��t֮��Ԫ�أ��������
*2018��8��17�� 23:50:07
*/
#include<iostream>
//����һ����k��¼���в�����x�ĸ�������ɨ���ͳ��k������������k��Ԫ����ǰ����kλ����,��Ϊk;
template<typename T>
void Del_x_1(T* A,int &n,T e) {
	int k = 0;
	for(int i=0;i<n;i++)
		if (A[i] != e) 
			A[k++] = A[i];
	n = k;
}
//����������k��¼���е���x�ĸ�������ɨ���ͳ��k������������k��Ԫ��ǰ��k��λ�ã���Ϊn-k
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
//ɾ��s��t֮���Ԫ��,��k��¼��Ԫ��ֵ��s��t֮��Ԫ�صĸ���������ֵ���ڷ�Χ֮�ڣ���ǰ��k��λ��
template<typename T>
bool Del_s_2(T* A, int &n, T s, T t) {
	int k = 0, i = 0;
	if (s >= t)return false;
	for (; i < n; i++) {
		if (A[i] >= s&&A[i] <= t)//��ɾ��x�İ汾2ֻ���б�������ͬ
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
