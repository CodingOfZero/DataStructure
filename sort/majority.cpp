/*
*majority��������
*���������ڣ����ȻΪ��λ��
*��PΪ����A�г���Ϊ2m��ǰ׺����Ԫ��x��P��ǡ�ó���m�Σ���A������������׺A-Pӵ����������A-P����������A��������
*/
#include<vector>
#include<iostream>
using std::vector;
//��ѡ��������֮
template<typename T>T majEleCandidate(vector<T> A) {
	T maj;//������ѡ�ߣ�ʼ��Ϊ��ǰǰ׺�г��ִ���������һ���ĳ��Ԫ��
	for (int c = 0,i=0; i < A.size(); i++) {//����������c����¼maj������Ԫ�ص��������
		if (0 == c)//ÿ��c���㣬����ζ�Ŵ�ʱ��ǰ׺p���Լ���
		{
			maj = A[i];
			c = 1;
		}
		else
			maj == A[i] ? c++ : c--;//���²�������
	}
	return maj;
}
//��֤��ѡ���Ƿ�Ϊ����
template<typename T>bool majEleCheck(vector<T> A,T maj)	{
	int occurrence = 0;
	for (int i = 0; i != A.size(); i++)
		if (A[i] == maj)
			occurrence++;
	return 2 * occurrence > A.size();
}
//��������
template<typename T>bool  majority(vector<T> A,T& maj) {
	maj = majEleCandidate(A);//��Ҫ�ԣ�ѡ����ѡ��maj
	return majEleCheck(A, maj); //����ԣ���֤maj�Ƿ��ȷ��ѡ
}
int main() {
	vector<int> t = { 5,3,9,3,3,1,2,3,3};
	int i = 0;
	if (majority(t, i))
		std::cout << i;
	else
		std::cout << "false";
}
