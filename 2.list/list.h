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
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {//ǰ�巨
	ListNodePosi x = new ListNode(e, pred, *this);	//�����½ڵ㣬ͬʱ�����x->pred=p->pred;x->succ=p;����
	pred->succ = x;
	pred = x;
	return x;
}
template<typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {//��巨
	ListNodePosi x = new ListNode(e, *this, succ);//�����½ڵ㣬ͬʱ�����x->pred=p; x->succ=p->succ;����
	succ->pred = x;
	succ = x;
	return x;
}
template<typename T>
ListNodePosi(T) List<T>::search(T const& e,int n, ListNodePosi(T) p) {//�������б��ڽڵ�p��n�ģ��棩ǰ���У��ҵ�������e�������
	while (0<=n--)
	{
		if ((p = p->pred)->data <= e)
			break;
	}
	return p;//���ز�����ֹ��λ��
}
//��������:�����ǰ׺������ĺ�׺;
template<typename T>
void List<T>::insertionSort(ListNodePosi(T)p,int n) {//����ʼ��λ��p��n��Ԫ������
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
//ѡ������:�����ǰ׺������ĺ�׺;
template<typename T>
void List<T>::selectionSort(ListNodePosi(T)p, int n) {//����ʼ��λ��p��n��Ԫ������
	ListNodePosi(T) head = p->pred; ListNodePosi(T) tail = p;
	for (int i = 0; i < n; i++)	//����������(head,tail)
		tail = tail->succ;
	while (1 < n)	//���ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
	{
		ListNodePosi(T) max = selectMax(head->succ, n);//����ʱ����������
		//insertB(tail, remove(max));//��ĩβʹ��ǰ�巨��max�����б�
		std::swap(tail->pred->data, max->data);
		tail = tail->pred;
		n--;
	}
}
//��·�鲢
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
	ListNodePosi(T) q = p; for (int i = 0; i < m; i++)q = q->succ;	//�����б�
	mergeSort(p, m);
	mergeSort(q, n-m);
	merge(p, m, *this, q, n - m);//�鲢
}//�����,p��Ȼָ��鲢������ģ��£����
//�б���
template<typename T>
void List<T>::reverse() {
	if (_size < 2)return;
	for (ListNodePosi(T)p = header; p; p = p->pred)
		std::swap(p->pred, p->succ);
	std::swap(header, trailer);//ͷβ�ڵ㻥��
}

