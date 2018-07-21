/*
*bitmap
*2018��7��21�� 21:21:31
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

	void set(int k) { expand(k); M[k >> 3] |= (0x80 >> (k & 0x07)); }	//������i���뵱ǰ����
	void clear(int k) { expand(k); M[k >> 3] &= ~(0x80 >> (k & 0x07)); }	//�ӵ�ǰ����ɾ������i
	bool test(int k) { expand(k); return M[k >> 3] & (0x80 >> (k & 0x07)); }	//�ж�����i�Ƿ����ڵ�ǰ����
	void expand(int k)	//�������ʵ�k�ѳ��磬��������
	{	
		if (k < 8 * N)	//���ڽ��ڣ���������
			return;
		int oldN = N;
		char *oldM = M;
		init(2 * k);	//�ӱ�����
		memcpy_s(M, N, oldM, oldN);	
		delete[]oldM;
	}
	char *bit_string(int n)	//��ǰnλת��Ϊ�ַ���
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
