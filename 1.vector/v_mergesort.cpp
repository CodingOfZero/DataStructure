/*
*�����Ĺ鲢����
*��������Ҫ�����������������Ĺ鲢���������������Ļ���ȴ��������ʱ�䣬������෴�� 
*2018��7��21�� 15:53:34
*/
#include<vector>
#include<iostream>
using std::vector;
template<typename T>
void v_merge(T *s,int lo,int mi, int hi);

template<typename T>
void v_mergesort(T *s, int lo, int hi) {
	if (hi - lo<2)	return;		//��Ԫ����Ȼ����
	int mi = (hi + lo) >> 1;
	v_mergesort(s, lo, mi);	//ǰ���
	v_mergesort(s, mi, hi);	//����
	v_merge(s,lo, mi, hi);	//�ϲ�
}
template<typename T>
void v_merge(T *s,int lo, int mi, int hi) {//���������������[lo,mi)��[mi,hi)
	T *A = s+lo;
	int lb = mi - lo;  T *B = new T[lb];	//ǰ������
	for (int i = 0; i<lb; B[i] = A[i++]);	//����ǰ������
	int lc = hi - mi;  T *C = s+mi;			//��������C[0,lc]=s[mi,hi)
	for (int i = 0, j = 0, k = 0; j<lb;)
	{														//����B[j] <= C[k]��ΪB[j] < C[k]��ѭ�����ڴ�������ʧЧ��������ѭ����
		if ((lc <= k) || (B[j] <= C[k]))	A[i++] = B[j++];//ֻҪǰ�߲����ں��ߣ�����������ȣ�����������ת��ǰ�ߣ�
		if ((k < lc) && (C[k] < B[j]))	A[i++] = C[k++];	//Ψ��ǰ���ϸ���ں��ߣ��ŻὫ����ת����A[i++]�Դ˱�֤�ȶ��ԣ�
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
