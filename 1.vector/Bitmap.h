/*
*bitmap
*2018年7月21日 21:21:31
*/
#include<cstring>
#include<iostream>
class Bitmap {
private:
	char *M; int N;
protected:
	void init(int n) { M = new char[N = (n + 7) / 8]; memset(M, 0, N); }
public:
	Bitmap(int n = 20) { init(n); }
	~Bitmap(){	delete[]M; M = NULL; }

	void set(int k) { expand(k); M[k >> 3] |= (0x80 >> (k & 0x07)); }	//将整数i加入当前集合
	void clear(int k) { expand(k); M[k >> 3] &= ~(0x80 >> (k & 0x07)); }	//从当前集合删除整数i
	bool test(int k) { expand(k); return M[k >> 3] & (0x80 >> (k & 0x07)); }	//判断整数i是否属于当前集合
	void expand(int k)	//若被访问的k已出界，则需扩容
	{	
		if (k < 8 * N)	//仍在界内，无需扩容
			return;
		int oldN = N;
		char *oldM = M;
		init(2 * k);	//加倍策略
		memcpy_s(M, N, oldM, oldN);	
		delete[]oldM;
	}
	char *bit_string(int n)	//将前n位转换为字符串
	{
		expand(n - 1);
		char *s = new char[n - 1]; s[n] = '\0';
		for (int i = 0; i < n; i++)
			s[i] = test(i) ? '1' : '0';
		return s;
	}
};
/*
int main(){
	Bitmap t;
	t.set(15);
	if (t.test(15))
		std::cout << "Yes"<<std::endl;
	else
		std::cout << "No";
	for(int i=0;i<20;i++)
		std::cout<<t.bit_string(20)[i];
}*/
