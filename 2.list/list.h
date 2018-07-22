#include<iostream>
#define ListNodePosi(T) ListNode<T>*
template<typename T>
struct ListNode {
	T data;
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;
	ListNode(){}
	ListNode(T e, ListNodePosi(T) p = nullptr,ListNodePosi(T) s=nullptr):data(a),pred(p),succ(s){}

	ListNodePosi(T) insertAsPred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};
template<typename T>class List
{
public:
	List() { init(); }
	~List()
	{
		clear(); delete header; delete trailer;
	}
	void init();
	void clear();
	T remove(ListNodePosi(T) p);
	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e) { _size++; return p->insertAsSucc; }
	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e) { _size++; return p->insertAsPred; }
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p);
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
	void insertionSort(ListNodePosi(T)p, int n);
	void selectionSort(ListNodePosi(T)p,int n);
	void mergeSort(ListNodePosi(T)&,int );
	void merge(ListNodePosi(T)& ,int ,List<T> &,ListNodePosi(T) ,int );
	void reverse(){}
private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;
};
template<typename T>
void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer; header->pred = nullptr;
	trailer->pred = header; trailer->succ = nullptr;
	_size = 0;
}
template<typename T> T List<T>::remove(ListNodePosi(T) p) {
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p; _size--;
	return e;
}
template<typename T>
void List<T>::clear() {
	while (0 < _size)
		remove(header->succ);
}
template<typename T> 
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {//前插法
	ListNodePosi x = new ListNode(e, pred, *this);	//创建新节点，同时完成了x->pred=p->pred;x->succ=p;操作
	pred->succ = x;
	pred = x;
	return x;
}
template<typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {//后插法
	ListNodePosi x = new ListNode(e, *this, succ);//创建新节点，同时完成了x->pred=p; x->succ=p->succ;操作
	succ->pred = x;
	succ = x;
	return x;
}
template<typename T>
ListNodePosi(T) List<T>::search(T const& e,int n, ListNodePosi(T) p) {//在有序列表内节点p的n的（真）前驱中，找到不大于e的最后者
	while (0<=n--)
	{
		if ((p = p->pred)->data <= e)
			break;
	}
	return p;//返回查找终止的位置
}
//插入排序:有序的前缀，无序的后缀;
template<typename T>
void List<T>::insertionSort(ListNodePosi(T)p,int n) {//对起始于位置p的n个元素排序
	for (int r = 0; r < n; r++)
	{
		insertA(search(p->data, r, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}

template<typename T>
bool lt(T x, T y) { x >= y ? true : false; }
template<typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T)p, int n) {
	ListNodePosi(T) max = p;
	for (ListNodePosi(T) cur = p; 1 < n; n--)
		if (lt((cur = cur->succ)->data, max->data))
			max = cur;
	return max;
}
//选择排序:无序的前缀，有序的后缀;
template<typename T>
void List<T>::selectionSort(ListNodePosi(T)p, int n) {//对起始于位置p的n个元素排序
	ListNodePosi(T) head = p->pred; ListNodePosi(T) tail = p;
	for (int i = 0; i < n; i++)	//待排序区间(head,tail)
		tail = tail->succ;
	while (1 < n)	//至少还剩两个节点之前，在待排序区间内
	{
		ListNodePosi(T) max = selectMax(head->succ, n);//歧义时，后者优先
		//insertB(tail, remove(max));//在末尾使用前插法将max插入列表
		std::swap(tail->pred->data, max->data);
		tail = tail->pred;
		n--;
	}
}
//二路归并
template<typename T>
void List<T>::merge(ListNodePosi(T)& p, int n, List<T> &L, ListNodePosi(T) q, int m) {
	ListNodePosi(T) pp = p->pred;
	while (0 < m)
	{
		if ((0<n)&&(p->data <= q->data))
		{
			if (q == (p = p->succ))break;
			n--;
		}	
		else
		{
			insertB(p, L.remove((q = q->succ)->pred));
			m--;
		}
	}
	p = pp->succ;
}
template<typename T>
void List<T>::mergeSort(ListNodePosi(T)& p, int n) {
	if (n < 2)return;
	int m = n >> 1;
	ListNodePosi(T) q = p; for (int i = 0; i < m; i++)q = q->succ;	//均分列表
	mergeSort(p, m);
	mergeSort(q, n-m);
	merge(p, m, *this, q, n - m);//归并
}//排序后,p仍然指向归并后区间的（新）起点
//列表倒置
template<typename T>
void List<T>::reverse() {
	if (_size < 2)return;
	for (ListNodePosi(T)p = header; p; p = p->pred)
		std::swap(p->pred, p->succ);
	std::swap(header, trailer);//头尾节点互换
}

