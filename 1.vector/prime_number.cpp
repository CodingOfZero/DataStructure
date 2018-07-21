/*
*埃拉托斯特尼筛法求素数
*计算出不大于n的所有素数
*2018年7月21日 22:31:25 
*/
#include"Bitmap.h"
#include<string>
using std::string;
int Eratosthenes(int n){
	Bitmap B(n);
	B.set(0);B.set(1);	//0和1都不是素数 
	for(int i=2;i<n;i++)
	{	 
		if(!B.test(i))
			for(int j=i*i;j<n;j+=i)	//从i^2开始出发，以i为间隔 
				B.set(j);	//将下一个数标记为合数 
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
