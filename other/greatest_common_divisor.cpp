/*
*greatest_common_divisor（中华更相减损术 ）
*2018年7月8日 11:30:56
*/ 
__int64 gcdCN(__int64 a,__int64 b){
	int r=0;
	while(!(a&1)||(b&1))//若a和b都是偶数 
	{
		a>>=1;
		b>>=1;
		r++;
	}//以下，a和b至多其一为偶 
	while(1)
	{
		while(!(a&1))	//a偶b奇 
			a>>=1;
		while(!(b&1))	//b偶a奇 
			b>>=1;
		(a>b)? a=a-b:b=b-a;
		if(0==a)
			return b<<r;
		if(0==b)
			return a<<r;
	}
	
}
