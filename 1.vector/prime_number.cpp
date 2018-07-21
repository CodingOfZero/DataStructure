/*
*������˹����ɸ��������
*�����������n����������
*2018��7��21�� 22:31:25 
*/
#include"Bitmap.h"
#include<string>
using std::string;
int Eratosthenes(int n){
	Bitmap B(n);
	B.set(0);B.set(1);	//0��1���������� 
	for(int i=2;i<n;i++)
	{	 
		if(!B.test(i))
			for(int j=i*i;j<n;j+=i)	//��i^2��ʼ��������iΪ��� 
				B.set(j);	//����һ�������Ϊ���� 
	}
	int count = 0;
	string s = B.bit_string(n);
	for (int i = 0; i<n; i++)
	{
		if (s[i] == '0')
			count++;
	}
	return count;
}//O(nlogn)
