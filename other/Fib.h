class Fib{
	private:
		int g,f;
	public:
		Fib(int n){f=1;g=0;while(g<n) next();}//��ʼ��Ϊ��С��n����СFibonacci�� 
		int get(){	return g;}
		int next(){g+=f;f=g-f;return g;}	//ת����һFibonacci�� 
		int prev(){ f=g-f;g-=f;return g;}	//ת����һFibonacci�� 
		
};
