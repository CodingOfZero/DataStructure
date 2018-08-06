/*
*binary_search_tree
*2018年8月6日 21:06:06 
*/
#include"BinTree.h"
//词条
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
	BinNodePosi(T) _hot;//"命中"节点的父亲
	BinNodePosi(T) connect34(//按照“3+4”结构联接3个节点及四棵子树
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
	BinNodePosi(T)rotateAt(BinNodePosi(T)x);//对x及其父亲、祖父做统一旋转调整
public://基本接口：以virtual修饰，强制要求所有派生类(BST)根据各自规则重写
	virtual BinNodePosi(T) &search(const T& e);//查找
	virtual BinNodePosi(T)insert(const T& e);//插入
	virtual bool remove(const T& e);//删除
};
//查找操作
template<typename T>
static BinNodePosi(T)& searchIn(BinNodePosi(T)& v, const T& e, BinNodePosi(T) &hot) {
	if (!v || (e == v->data))return v;//递归基：在节点v(或假想的通配节点)命中
	hot = v;//记录当前节点
	return searchIn(((e < v->data) ? v->lc : v->rc), e, hot);//深入一层，递归查找
}//返回时，返回值指向命中节点（或假想的通配哨兵），hot指向其父亲（退化是为初始值NULL）
template<typename T> BinNodePosi(T)& BST<T>::search(const T& e) {
	return searchIn(_root, e, _hot = NULL);
}
//插入
template<typename T> BinNodePosi(T) BST<T>::insert(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (x) return x;
	x = new BinNode<T>(e, _hot);
	_size++;
	updateHeightAbove(x);//更新x及其历代祖先的高度
	return x;
}
//删除
/*
*删除位置x所指的节点
*目标在此前经查找定位，并确认非NULL；与searchIn不同，调用之前不必将hot置空；
*返回值指向实际被删除节点的接替者，hot指向实际被删除节点的父亲--二者均有可能是NULL
*/
template<typename T>
static BinNodePosi(T)removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) {
	BinNodePosi(T) w = x;
	BinNodePosi(T) succ = NULL;//实际被删除节点的接替者
	if (!HasLChild(*x))//若*x的左子树为空，直接将用右子树替换
		succ = x = x->rc;
	else if (!HasRChild(*x))//若*x的右子树为空，对称处理，（此时succ!=NULL）
		succ = x = x->lc;
	else {
		w = w->succ();//在右子树中找到*x的直接后继*w
		swap(x->data, w->data);//交换数据元素
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc;//隔离节点*w
	}
	hot = w->parent;//记录实际被删除节点的父亲
	if (succ) succ->parent = hot;
	release(w->data);
	release(w);
	return succ;//返回接替者
}
template<typename T> bool BST<T>::remove(const T& e) {
	BinNodePosi(T) &x = search(e);
	if (!x) return false;
	removeAt(x, _hot);//实施删除
	_size--;
	updateHeightAbove(_hot);//更新_hot及其历代祖先的高度
	return ture;
}

