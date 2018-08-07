#include"BST.h"
#define Balanced(x) (stature((x).lc)==stature((x).rc))//����ƽ������
#define BalFac(x)(stature((x).lc)-stature((x).rc))//ƽ������
#define AvlBalanced(x)((-2<BalFac(x))&&(BalFac(x)<2))//AVLƽ������
template<typename T> class AVL :public BST<T> {
public:
	BinNodePosi(T) insert(const T&e);//��д
	bool remove(const T&e);
private:
	BinNodePosi(T) tallerChild(BinNodePosi(T) x) {
		stature(x->lc) > stature(x->rc) ? x->lc : (stature(x->lc) < stature(x->rc) ? x->rc : (IsLChild(*x) ? x->lc : x->rc));
	}
};
template<typename T> BinNodePosi(T) AVL<T>::insert(const T& e) {
	BinNodePosi(T) &x = search(e); if (x) return x;
	BinNodePosi(T)xx = x = new BinNode<T>(e, _hot); _size++;
	//x�ĸ���_hot�����ߣ������游�п���ʧ��;����ֻ��һ�ε���;������������������ȫ���߶ȱ�Ȼ��ԭ
	for (BinNodePosi(T) g = _hot; g; g->parent) 
	{
		if (!AvlBalanced(*g))//gʧ�⣬���ã�3+4�㷨��ʹ֮����
		{
			FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
			break;//����󣬾ֲ������߶ȱ�Ȼ��ԭ�������������ˣ��ʵ����漴����
		}
		else
			updateHeight(g);//������߶ȣ�����gδʧ�⣬�߶���������ӣ�
	}
	return xx;
}
template<typename T> bool AVL<T>::remove(const T& e) {//��AVL����ɾ���ؼ���e
	BinNodePosi(T)& x = search(e); if (!x)return false;
	removeAt(x, _hot); _size--;
	for (BinNodePosi(T)g = _hot; g; g = g->parent)//��_hot�������ϣ�������������g
	{
		if (!AvlBalanced(*g))//gʧ�⣬���ã�3+4�㷨��ʹ֮���⣬��������������ԭ����
			g= FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
		updateHeight(g);//������߶ȣ�����gδʧ�⣬�߶�����ܽ��ͣ�
	}
	return true;
}

