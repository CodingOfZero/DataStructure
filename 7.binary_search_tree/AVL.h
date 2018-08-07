#include"BST.h"
#define Balanced(x) (stature((x).lc)==stature((x).rc))//理想平衡条件
#define BalFac(x)(stature((x).lc)-stature((x).rc))//平衡因子
#define AvlBalanced(x)((-2<BalFac(x))&&(BalFac(x)<2))//AVL平衡条件
template<typename T> class AVL :public BST<T> {
public:
	BinNodePosi(T) insert(const T&e);//重写
	bool remove(const T&e);
private:
	BinNodePosi(T) tallerChild(BinNodePosi(T) x) {
		stature(x->lc) > stature(x->rc) ? x->lc : (stature(x->lc) < stature(x->rc) ? x->rc : (IsLChild(*x) ? x->lc : x->rc));
	}
};
template<typename T> BinNodePosi(T) AVL<T>::insert(const T& e) {
	BinNodePosi(T) &x = search(e); if (x) return x;
	BinNodePosi(T)xx = x = new BinNode<T>(e, _hot); _size++;
	//x的父亲_hot若增高，则其祖父有可能失衡;至多只需一次调整;若果真做过调整，则全树高度必然复原
	for (BinNodePosi(T) g = _hot; g; g->parent) 
	{
		if (!AvlBalanced(*g))//g失衡，采用（3+4算法）使之复衡
		{
			FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
			break;//复衡后，局部子树高度必然复原；其祖先亦必如此，故调整随即结束
		}
		else
			updateHeight(g);//更新其高度（即便g未失衡，高度亦可能增加）
	}
	return xx;
}
template<typename T> bool AVL<T>::remove(const T& e) {//从AVL树中删除关键码e
	BinNodePosi(T)& x = search(e); if (!x)return false;
	removeAt(x, _hot); _size--;
	for (BinNodePosi(T)g = _hot; g; g = g->parent)//从_hot出发向上，逐层检测各代祖先g
	{
		if (!AvlBalanced(*g))//g失衡，采用（3+4算法）使之复衡，并将该子树联至原父亲
			g= FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
		updateHeight(g);//更新其高度（即便g未失衡，高度亦可能降低）
	}
	return true;
}

