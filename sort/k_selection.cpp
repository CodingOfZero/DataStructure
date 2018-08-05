/*
*K-Selection
*2018��8��4�� 23:26:28
*�㷨��Ҫ��������
select(A,k)
���룺��ģΪn����������A����K>=0
�����A����Ӧ������������Ϊk��Ԫ��
{
	if(n==|A|<Q) return trivialSelect(A,k);//�ݹ�������й�ģ����ʱֱ��ʹ�������㷨
	��A���ȵػ���Ϊn/Q�������У�����Q��Ԫ��;//QΪ5
	�������зֱ����򣬼�����λ����������Щ��λ�����һ������;//�ɲ����κ������㷨
	ͨ���ݹ����select()���������λ�����е���λ��������M;
	�����������M�Ĵ�С����A��Ԫ�ط�Ϊ�����Ӽ���L(С��),E(���),G(����);
	if(|L|>=k) return select(L,k);
	else if(|L|+|E|>=k) return M;
	else return select(G,k-|L|-|E|);
}//��������ȻΪO(n)
*/
#include<iostream>
#include<vector>
using std::vector;
//���ڿ��ٻ��ֵ�kѡȡ�㷨O(n*2)
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
