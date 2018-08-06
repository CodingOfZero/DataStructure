/*
*complete binary heap(��ȫ�����)
*2018��8��5�� 15:43:53
*/
#include<vector>
#include<iostream>
using namespace std;
template <typename T> class PQ_ComplHeap {
protected:
	int percolateDown(int n, int i);//����
	int percolateUp(int i);//����
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
	int LChild(int i) { return (1 + (i << 1)); }//����
	int RChild(int i) { return((i + 1) << 1); }//�Һ���
	int Parent(int i) { return ((i - 1) >> 1); }//PQ[i]�ĸ��ڵ�
	int LastInternal(int n) { return Parent(n - 1); }//���һ���ڲ��ڵ�(��ĩ�ڵ�ĸ��ڵ�)
	bool ParentVaild(int i)	{return 0 < i ? true : false;}
	bool LChildVaild(int n, int i) { return InHeap(n, LChild(i)); }//�ж��Ƿ���һ������
	bool RChildVaild(int n, int i) { return InHeap(n, RChild(i)); }//�ж��Ƿ�����������
	int Bigger(int i,int j) { return (_elem[i] < _elem[j] ? j : i); }//����ȡ���ߣ���ʱǰ������
	int ProperParent(int n, int i) { 
		return (RChildVaild(n, i) ? Bigger(Bigger(i, RChild(i)), LChild(i)) : (LChildVaild(n,i) ? Bigger(i, LChild(i)) : i));
	}//������ȡ���ֵ
};
template <typename T> int PQ_ComplHeap<T>::percolateUp(int i) { //����
	while (ParentVaild(i))//ֻҪi�и��ף�δ��Ѷ��� 
	{
		int j = Parent(i);
		if (_elem[i] <= _elem[j])	break;//һ����ǰ���Ӳ��������������
		swap(_elem[i], _elem[j]);//���򣬸��ӽ���λ�ã�������������һ��
		i = j;
	}
	return i;//�����������յִ��λ��
}
//������ǰn�������еĵ�i��ʵʩ����,i<n
template <typename T> int PQ_ComplHeap<T>::percolateDown(int n,int i) {
	int j;
	while (i != (j = ProperParent( n, i)))
	{
		swap(_elem[i], _elem[j]);
		i = j;
	}
	return i;//�������˵ִ��λ��
}
template <typename T> T PQ_ComplHeap<T>::getMax() { return _elem[0]; }
template <typename T> void PQ_ComplHeap<T>::insert(T e) { 
	_elem.push_back(e);
	percolateUp(_elem.size() - 1);//����
}
template <typename T> T PQ_ComplHeap<T>::delMax() {
	T maxElem = _elem[0];
	_elem[0] = _elem[_elem.size()-1];
	if (!_elem.empty())
		_elem.pop_back();
	percolateDown(_elem.size(), 0);
	return maxElem;
}
//Floyd�����㷨��O(n)ʱ�� ���¶��ϵ�����
template <typename T> void PQ_ComplHeap<T>::Floyd_heap(int n) {
	for (int i = LastInternal(n); InHeap(n, i); i--)
		percolateDown(n, i);
}
//������(ֻ�Ǽ򵥲���)
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

