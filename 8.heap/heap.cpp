/*
*complete binary heap(完全二叉堆)
*2018年8月5日 15:43:53
*/
#include<vector>
#include<iostream>
using namespace std;
template <typename T> class PQ_ComplHeap {
protected:
	int percolateDown(int n, int i);//下滤
	int percolateUp(int i);//上滤
	void Floyd_heap(int n);
public:
	PQ_ComplHeap() { Floyd_heap(5); }
	//PQ_ComplHeap(T*A ,int n){copy}
	T getMax();
	T delMax();
	void insert(T);
//	vector<T> heapsort();
	size_t size() { return _elem.size(); }
	bool empty() { return _elem.empty(); }
private:
	vector<T> _elem = { 3,6,73,3,21 };
	bool InHeap(int n, int i) { return ((-1) < (i)) && (i < n); }
	int LChild(int i) { return (1 + (i << 1)); }//左孩子
	int RChild(int i) { return((i + 1) << 1); }//右孩子
	int Parent(int i) { return ((i - 1) >> 1); }//PQ[i]的父节点
	int LastInternal(int n) { return Parent(n - 1); }//最后一个内部节点(即末节点的父节点)
	bool ParentVaild(int i)	{return 0 < i ? true : false;}
	bool LChildVaild(int n, int i) { return InHeap(n, LChild(i)); }//判断是否有一个左孩子
	bool RChildVaild(int n, int i) { return InHeap(n, RChild(i)); }//判断是否有两个孩子
	int Bigger(int i,int j) { return (_elem[i] < _elem[j] ? j : i); }//两者取大者，等时前者优先
	int ProperParent(int n, int i) { 
		return (RChildVaild(n, i) ? Bigger(Bigger(i, RChild(i)), LChild(i)) : (LChildVaild(n,i) ? Bigger(i, LChild(i)) : i));
	}//三者中取最大值
};
template <typename T> int PQ_ComplHeap<T>::percolateUp(int i) { //上滤
	while (ParentVaild(i))//只要i有父亲（未达堆顶） 
	{
		int j = Parent(i);
		if (_elem[i] <= _elem[j])	break;//一旦当前父子不再逆序，上滤完成
		swap(_elem[i], _elem[j]);//否则，父子交换位置，并继续考查下一层
		i = j;
	}
	return i;//返回上滤最终抵达的位置
}
//对向量前n个词条中的第i个实施下滤,i<n
template <typename T> int PQ_ComplHeap<T>::percolateDown(int n,int i) {
	int j;
	while (i != (j = ProperParent( n, i)))
	{
		swap(_elem[i], _elem[j]);
		i = j;
	}
	return i;//返回下滤抵达的位置
}
template <typename T> T PQ_ComplHeap<T>::getMax() { return _elem[0]; }
template <typename T> void PQ_ComplHeap<T>::insert(T e) { 
	_elem.push_back(e);
	percolateUp(_elem.size() - 1);//上滤
}
template <typename T> T PQ_ComplHeap<T>::delMax() {
	T maxElem = _elem[0];
	_elem[0] = _elem[_elem.size()-1];
	if (!_elem.empty())
		_elem.pop_back();
	percolateDown(_elem.size(), 0);
	return maxElem;
}
//Floyd建堆算法，O(n)时间 自下而上的下滤
template <typename T> void PQ_ComplHeap<T>::Floyd_heap(int n) {
	for (int i = LastInternal(n); InHeap(n, i); i--)
		percolateDown(n, i);
}
//堆排序(只是简单测试)
/*template <typename T> vector<T> PQ_ComplHeap<T>::heapsort() {
	Floyd_heap(5);
	vector<T>  t;
	while (!_elem.empty())
		t.push_back(delMax());
	return t;
}*/
int main() {
	PQ_ComplHeap<int> t ;
	cout << t.getMax() << endl;
	/*for (auto &a : t.heapsort())
		cout << a<<endl;*/
}

