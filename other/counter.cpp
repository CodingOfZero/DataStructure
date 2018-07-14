/*
*统计整数二进制展开中数位1的总数 
*2018年7月7日 22:07:04 
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

int countOnes1(int n){  //O(countOnes(n)),线性正比于数位1的实际数目 
	int ones=0;	//计数器复位 
	while(0<n)
	{
		ones++;	//计数至少有一位为1 
		n &=n-1;
	}
	return ones;
}

/*
*汉明重量 
*/
#define POW(c) (1<<(c)) //2^c
#define MASK(c) (((unsigned long) -1) / (POW(POW(c))+1))  //以2^c位为单位分组，相间地全0和全1 
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
}//32位字长时，O(log_2(32)) = O(5) = O(1) 
int main(){

//	std::cout<<countOnes(478784123)<<std::endl;
//	std::cout<<countOnes1(478784123)<<std::endl;	
	std::cout<<countOnes2(478784127)<<std::endl;
	
}











