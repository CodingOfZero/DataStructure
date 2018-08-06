/*
*binary_search_tree
*2018��8��6�� 21:06:06 
*/
#include"BinTree.h"
//����
template<typename K, typename V> struct Entry{
	K key;	V value;
	Entry(K k, V v) :key(k), value(v) {}
	Entry(Entry<K,V>const &e):key(e.key),value(e.value){}
	bool operator <(Entry<K, V>const& e) { return key < e.key; }
	bool operator >(Entry<K, V>const& e) { return key > e.key; }
	bool operator ==(Entry<K, V>const& e) { return key == e.key; }
	bool operator !=(Entry<K, V>const& e) { return key != e.key; }
};
template<typename T> class BST: public BinTree<T>{
protected:
	BinNodePosi(T) _hot;//"����"�ڵ�ĸ���
	BinNodePosi(T) connect34(//���ա�3+4���ṹ����3���ڵ㼰�Ŀ�����
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
	BinNodePosi(T)rotateAt(BinNodePosi(T)x);//��x���丸�ס��游��ͳһ��ת����
public://�����ӿڣ���virtual���Σ�ǿ��Ҫ������������(BST)���ݸ��Թ�����д
	virtual BinNodePosi(T) &search(const T& e);//����
	virtual BinNodePosi(T)insert(const T& e);//����
	virtual bool remove(const T& e);//ɾ��
};
//���Ҳ���
template<typename T>
static BinNodePosi(T)& searchIn(BinNodePosi(T)& v, const T& e, BinNodePosi(T) &hot) {
	if (!v || (e == v->data))return v;//�ݹ�����ڽڵ�v(������ͨ��ڵ�)����
	hot = v;//��¼��ǰ�ڵ�
	return searchIn(((e < v->data) ? v->lc : v->rc), e, hot);//����һ�㣬�ݹ����
}//����ʱ������ֵָ�����нڵ㣨������ͨ���ڱ�����hotָ���丸�ף��˻���Ϊ��ʼֵNULL��
template<typename T> BinNodePosi(T)& BST<T>::search(const T& e) {
	return searchIn(_root, e, _hot = NULL);
}
//����
template<typename T> BinNodePosi(T) BST<T>::insert(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (x) return x;
	x = new BinNode<T>(e, _hot);
	_size++;
	updateHeightAbove(x);//����x�����������ȵĸ߶�
	return x;
}
//ɾ��
/*
*ɾ��λ��x��ָ�Ľڵ�
*Ŀ���ڴ�ǰ�����Ҷ�λ����ȷ�Ϸ�NULL����searchIn��ͬ������֮ǰ���ؽ�hot�ÿգ�
*����ֵָ��ʵ�ʱ�ɾ���ڵ�Ľ����ߣ�hotָ��ʵ�ʱ�ɾ���ڵ�ĸ���--���߾��п�����NULL
*/
template<typename T>
static BinNodePosi(T)removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) {
	BinNodePosi(T) w = x;
	BinNodePosi(T) succ = NULL;//ʵ�ʱ�ɾ���ڵ�Ľ�����
	if (!HasLChild(*x))//��*x��������Ϊ�գ�ֱ�ӽ����������滻
		succ = x = x->rc;
	else if (!HasRChild(*x))//��*x��������Ϊ�գ��Գƴ�������ʱsucc!=NULL��
		succ = x = x->lc;
	else {
		w = w->succ();//�����������ҵ�*x��ֱ�Ӻ��*w
		swap(x->data, w->data);//��������Ԫ��
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc;//����ڵ�*w
	}
	hot = w->parent;//��¼ʵ�ʱ�ɾ���ڵ�ĸ���
	if (succ) succ->parent = hot;
	release(w->data);
	release(w);
	return succ;//���ؽ�����
}
template<typename T> bool BST<T>::remove(const T& e) {
	BinNodePosi(T) &x = search(e);
	if (!x) return false;
	removeAt(x, _hot);//ʵʩɾ��
	_size--;
	updateHeightAbove(_hot);//����_hot�����������ȵĸ߶�
	return ture;
}

