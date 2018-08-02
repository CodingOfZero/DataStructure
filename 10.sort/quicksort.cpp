/*
*quicksort
*可以在O(1)时间内，由子问题的解直接得到原问题的解；但为了将原问题划分为两个子问题，却需要O(n)时间；与归并排序相反 
*2018年8月2日 14:51:28
*/
#include<iostream>
#include<vector>
using std::vector;
//轴点构造：通过调整元素位置构造区间[lo,hi]的轴点，并返回其秩
//版本A：勤于拓展，懒于交换;
template<typename T>
int partition_A(vector<T>& _elem, int lo, int hi) {
	std::swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);//任选一个元素与首元素交换
	T pivot = _elem[lo];	//以首元素为候选轴点
	while (lo < hi)
	{
		while ((lo < hi) && (pivot <= _elem[hi]))//在不小于pivot的前提下，向左扩展右端子向量
			hi--;
		_elem[lo] = _elem[hi];	//小于pivot者归入左侧子序列
		while ((lo < hi) && (_elem[lo] <= pivot))
			lo++;
		_elem[hi] = _elem[lo];
	}
	_elem[lo] = pivot;//将备份的轴点记录于前、后子向量之间
	return lo;
}
//版本B：懒于拓展，勤于交换;
/*对于大量重复输入元素，可以交替转移，并最终恰好将轴点置于正中央的位置，
使得退化的输入向量能够始终被均衡的切分，如此反而成为最好情况，排序时间O(nlogn)*/
template<typename T>
int partition_B(vector<T>& _elem, int lo, int hi) {
	std::swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
	T pivot = _elem[lo];	
	while (lo < hi)
	{
		while (lo < hi) {
			if (pivot < _elem[hi])//在大于pivot的前提下，向左扩展右端子向量;
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
	int mi = partition_A(_elem, lo, hi - 1);//最后一个实参为hi-1，使得构造轴点函数时简洁;
	quickSort(_elem, lo, mi);
	quickSort(_elem, mi + 1, hi);
}//O(nlogn)常系数更小为 O(1.386logn) 
int main() {
	vector<int> t = { 2,5,78,9,43,9,0,3,23 };
	quickSort(t, 0, 9);
	for (auto &s : t)
		std::cout << s<<" " ;
}
