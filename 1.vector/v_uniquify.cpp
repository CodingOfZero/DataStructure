/*
*有序向量的唯一化
*2018年7月21日 15:53:34 
*/
#include<vector>
#include<iostream>
using std::vector;
template<typename T>
void v_uniquify(vector<T>& s) {
	int i = 0, j = 0;
	while (++j<s.size())
		if (s[i] != s[j])
			s[++i] = s[j];
	s.resize(++i);
}
/*
int main() {
	vector<int> t = { 1,3,5,5,5,5,6,7 };
	v_uniquify(t);
	for (auto a : t)
		std::cout << a;
	return 0;
}*/
