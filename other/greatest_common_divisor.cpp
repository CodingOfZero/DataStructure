/*
*greatest_common_divisor���л���������� ��
*2018��7��8�� 11:30:56
*/ 
__int64 gcdCN(__int64 a,__int64 b){
	int r=0;
	while(!(a&1)||(b&1))//��a��b����ż�� 
	{
		a>>=1;
		b>>=1;
		r++;
	}//���£�a��b������һΪż 
	while(1)
	{
		while(!(a&1))	//ażb�� 
			a>>=1;
		while(!(b&1))	//bża�� 
			b>>=1;
		(a>b)? a=a-b:b=b-a;
		if(0==a)
			return b<<r;
		if(0==b)
			return a<<r;
	}
	
}
