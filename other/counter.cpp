/*
*ͳ������������չ������λ1������ 
*2018��7��7�� 22:07:04 
*/ 
#include<iostream>
#include<time.h>

int countOnes(int n){  //O(logn)
	int counter=0;
	while (0<n)
	{
		counter+=(1&n);
		n>>=1;	
	}
	return counter;
}

int countOnes1(int n){  //O(countOnes(n)),������������λ1��ʵ����Ŀ 
	int ones=0;	//��������λ 
	while(0<n)
	{
		ones++;	//����������һλΪ1 
		n &=n-1;
	}
	return ones;
}

/*
*�������� 
*/
#define POW(c) (1<<(c)) //2^c
#define MASK(c) (((unsigned long) -1) / (POW(POW(c))+1))  //��2^cλΪ��λ���飬����ȫ0��ȫ1 
//MASK(0) = 55555555(h) = 01010101010101010101010101010101(b)
//MASK(1) = 33333333(h) = 00110011001100110011001100110011(b)
//MASK(2) = 0f0f0f0f(h) = 00001111000011110000111100001111(b)
//MASK(3) = 00ff00ff(h) = 00000000111111110000000011111111(b)
//MASK(4) = 0000ffff(h) = 00000000000000001111111111111111(b)
#define ROUND(n,c) (((n) & MASK(c))+((n) >> POW(c) & MASK(c)))

int countOnes2 (unsigned int n) {
	n = ROUND(n,0);
	n = ROUND(n,1);
	n = ROUND(n,2);
	n = ROUND(n,3);
	n = ROUND(n,4);
	return n;
}//32λ�ֳ�ʱ��O(log_2(32)) = O(5) = O(1) 
int main(){

//	std::cout<<countOnes(478784123)<<std::endl;
//	std::cout<<countOnes1(478784123)<<std::endl;	
	std::cout<<countOnes2(478784127)<<std::endl;
	
}











