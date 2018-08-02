/*
*majority（众数）
*若众数存在，则必然为中位数
*设P为向量A中长度为2m的前缀。若元素x在P中恰好出现m次，则A有众数仅当后缀A-P拥有众数，且A-P的众数就是A的众数。
*/
#include<vector>
#include<iostream>
using std::vector;
//候选：减而治之
template<typename T>T majEleCandidate(vector<T> A) {
	T maj;//众数候选者，始终为当前前缀中出现次数不少于一半的某个元素
	for (int c = 0,i=0; i < A.size(); i++) {//借助计数器c，记录maj与其他元素的数量差额
		if (0 == c)//每当c归零，都意味着此时的前缀p可以剪除
		{
			maj = A[i];
			c = 1;
		}
		else
			maj == A[i] ? c++ : c--;//更新差额计数器
	}
	return maj;
}
//验证候选者是否为众数
template<typename T>bool majEleCheck(vector<T> A,T maj)	{
	int occurrence = 0;
	for (int i = 0; i != A.size(); i++)
		if (A[i] == maj)
			occurrence++;
	return 2 * occurrence > A.size();
}
//众数查找
template<typename T>bool  majority(vector<T> A,T& maj) {
	maj = majEleCandidate(A);//必要性：选出候选者maj
	return majEleCheck(A, maj); //充分性：验证maj是否的确当选
}
int main() {
	vector<int> t = { 5,3,9,3,3,1,2,3,3};
	int i = 0;
	if (majority(t, i))
		std::cout << i;
	else
		std::cout << "false";
}
