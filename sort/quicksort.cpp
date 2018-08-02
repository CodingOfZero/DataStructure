/*
*quicksort
*������O(1)ʱ���ڣ���������Ľ�ֱ�ӵõ�ԭ����Ľ⣻��Ϊ�˽�ԭ���⻮��Ϊ���������⣬ȴ��ҪO(n)ʱ�䣻��鲢�����෴ 
*2018��8��2�� 14:51:28
*/
#include<iostream>
#include<vector>
using std::vector;
//��㹹�죺ͨ������Ԫ��λ�ù�������[lo,hi]����㣬����������
//�汾A��������չ�����ڽ���;
template<typename T>
int partition_A(vector<T>& _elem, int lo, int hi) {
	std::swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);//��ѡһ��Ԫ������Ԫ�ؽ���
	T pivot = _elem[lo];	//����Ԫ��Ϊ��ѡ���
	while (lo < hi)
	{
		while ((lo < hi) && (pivot <= _elem[hi]))//�ڲ�С��pivot��ǰ���£�������չ�Ҷ�������
			hi--;
		_elem[lo] = _elem[hi];	//С��pivot�߹������������
		while ((lo < hi) && (_elem[lo] <= pivot))
			lo++;
		_elem[hi] = _elem[lo];
	}
	_elem[lo] = pivot;//�����ݵ�����¼��ǰ����������֮��
	return lo;
}
//�汾B��������չ�����ڽ���;
/*���ڴ����ظ�����Ԫ�أ����Խ���ת�ƣ�������ǡ�ý���������������λ�ã�
ʹ���˻������������ܹ�ʼ�ձ�������з֣���˷�����Ϊ������������ʱ��O(nlogn)*/
template<typename T>
int partition_B(vector<T>& _elem, int lo, int hi) {
	std::swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
	T pivot = _elem[lo];	
	while (lo < hi)
	{
		while (lo < hi) {
			if (pivot < _elem[hi])//�ڴ���pivot��ǰ���£�������չ�Ҷ�������;
				hi--;
			else
			{
				_elem[lo++] = _elem[hi];
				break;
			}
		}
		while (lo < hi) {
			if (_elem[lo] < pivot)
				lo++;
			else
			{
				_elem[hi--] = _elem[lo];
				break;
			}
		}
	}
	_elem[lo] = pivot;
	return lo;
}
template<typename T>
void quickSort(vector<T> &_elem, int lo, int hi){
	if (hi - lo < 2)return;
	int mi = partition_A(_elem, lo, hi - 1);//���һ��ʵ��Ϊhi-1��ʹ�ù�����㺯��ʱ���;
	quickSort(_elem, lo, mi);
	quickSort(_elem, mi + 1, hi);
}//O(nlogn)��ϵ����СΪ O(1.386logn) 
int main() {
	vector<int> t = { 2,5,78,9,43,9,0,3,23 };
	quickSort(t, 0, 9);
	for (auto &s : t)
		std::cout << s<<" " ;
}
