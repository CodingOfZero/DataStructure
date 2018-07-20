class Fib{
	private:
		int g,f;
	public:
		Fib(int n){f=1;g=0;while(g<n) next();}//初始化为不小于n的最小Fibonacci项 
		int get(){	return g;}
		int next(){g+=f;f=g-f;return g;}	//转至下一Fibonacci项 
		int prev(){ f=g-f;g-=f;return g;}	//转至上一Fibonacci项 
		
};
