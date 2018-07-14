/*
*Power_function2^n 
*2018��7��7�� 22:03:32 
*/ 
#include<iostream>

__int64 power2BF_I(int n){ //���������� 
	__int64 pow=1;
	while(0<n--)
		pow<<=1;
	return pow;
} //O(n)=O(2^r) ,rΪ����ָ��n�ı�����

inline __int64 sqr(__int64 a){
	return a*a;
} 
__int64 power2(int n){	//�Ż��ݹ�� 
	if(0==n)
		return 1;
	return (n&1) ? sqr(power2(n>>1))<<1 : sqr(power2(n>>1));
}//O(logn)=O(r),rΪ����ָ��n�ı�����

__int64 powerA_I(__int64 a,int n){	//a^nͨ���㷨���Ż������棩 
	__int64 pow = 1;
	__int64 p =a;
	while(0<n)
	{
		if(1&n)
			pow*=p;
		n>>=1;
		p*=p;
	}
	return pow;
}//O(logn)=O(r),rΪ����ָ��n�ı�����

int main(){
	int n=0;
	int t=0;
	while(1)
	{
		std::cin>>t>>n;
	//	std::cout<<power2BF_I(n);
	//	std::cout<<power2(n);
		
		std::cout<<powerA_I(t,n);
	}

}
