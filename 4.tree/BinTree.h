/*
*Tree
*2018��7��23�� 23:03:25 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using std::queue;
using std::stack;
using std::vector;
#define stature(p)((p)?(p)->height:-1)
#define BinNodePosi(T) BinNode<T>*
#define IsRoot(x)(!((x).parent))
#define IsLChild(x)(!IsRoot&&(&(x)==(x).parent->lc))
#define IsRChild(x)(!IsRoot&&(&(x)==(x).parent->rc))
#define HasLChild(x)((x).lc)
#define HasRChild(x)((x).rc)
template <typename T> struct BinNode {
	T data;
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
	int height;
	BinNode(T e, BinNodePosi(T)p = NULL, BinNodePosi(T)lc = NULL, BinNodePosi(T)rc = NULL, int h = 0) :data(e), parent(p), lc(lc), rc(rc), height(h) {}
	BinNodePosi(T) insertAsLC(T const&);//��Ϊ��ǰ�ڵ�����Ӳ����½ڵ�
	BinNodePosi(T) insertAsRC(T const&);//��Ϊ��ǰ�ڵ���Һ��Ӳ����½ڵ�
	BinNodePosi(T) succ();//ȡ��ǰ�ڵ��ֱ�Ӻ��

};
template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e) {
	return  lc = new BinNode(e,*this);
}
template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e) {
	return  rc = new BinNode(e, *this);
}
template<typename T>BinNodePosi(T) BinNode<T>::succ() {
	BinNodePosi(T) s = this;
	if (rc)	//�����Һ��ӣ���ֱ�Ӻ�̱�����������
	{
		s = rc;
		while (HasLChild(*s))	s = s->lc;//���ڵ�
	}
	else//����ֱ�Ӻ���ǡ�����ǰ�ڵ����������������������ȡ�
	{
		while (IsRChild(*s))	s = s->parent;//������������֧�����ϳ����Ϸ��ƶ�
		s = s->parent;//����ٳ����Ϸ��ƶ�һ��������ֱ�Ӻ��
	}
}
template <typename T> class BinTree {
protected:
	int _size; BinNodePosi(T) _root;
	int updateHeight(BinNodePosi(T) x);//���½ڵ�x�ĸ߶�
	void updateHeightAbove(BinNodePosi(T) x);//���¸߶�
public:
	BinTree():_size(0),_root(NULL){}
	BinNodePosi(T) insertAsRoot(T const&e) ;
	BinNodePosi(T) insertAsLc(BinNodePosi(T) x, T const& e) ;//e��Ϊx�����ӣ�ԭ�ޣ�����
	BinNodePosi(T) insertAsRc(BinNodePosi(T) x, T const& e) ;//e��Ϊx���Һ��ӣ�ԭ�ޣ�����
	BinNodePosi(T) attachAsLc(BinNodePosi(T) x, BinTree<T>* &T) ;//T��Ϊ����������
	BinNodePosi(T) attachAsRc(BinNodePosi(T) x, BinTree<T>* &T) ;//T��Ϊ����������
	//����
	vector<T> Preorder_Traversal(BinNodePosi(T) x);
	vector<T> Inorder_Traversal(BinNodePosi(T) x);
	vector<T> Postorder_Traversal(BinNodePosi(T) x);
	vector<T> levelorder_Traversal(BinNodePosi(T) x);
};
template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x) {
	return x->heigh = 1 + std::max(stature(x->lc), stature(x->rc));
}
template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) {
	while (x) {
		updateHeight(x);
		x = x->parent;
	}
}
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const&e) {
	_size = 1;
	return _root = new BinNode<T>(e);
}
template <typename T> BinNodePosi(T) BinTree<T>::insertAsLc(BinNodePosi(T) x, T const& e) {
	_size++;
	x->insertAsLC(e);
	updateHeightAbove(x);
	return x->lc;
}
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRc(BinNodePosi(T) x, T const& e) {
	_size++;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rc;
}
template <typename T> BinNodePosi(T) BinTree<T>::attachAsLc(BinNodePosi(T) x, BinTree<T>* &S) {
	if (x->lc = S->_root)
		x->lc->parent = x;
	_size += S->_size;
	updateHeightAbove(x);
	S->_root = NULL;
	S->_size = 0;
	release(S);
	return x;
}
template <typename T> BinNodePosi(T) BinTree<T>::attachAsRc(BinNodePosi(T) x, BinTree<T>* &S) {
	if (x->rc = S->_root)	
		x->rc->parent = x;
	_size += S->_size;
	updateHeightAbove(x);
	S->_root = NULL;
	S->_size = 0;
	relase(S);
	return x;
}

template <typename T> vector<T> BinTree<T>::Preorder_Traversal(BinNodePosi(T) x) {//�������
	stack<BinNodePosi(T)> S;//����ջ
	vector<T> output;
	while (true) {
		while (x) {				//����visit������������ֱ�������ڵ�
			output.push_back(x->data);		//visit(x);
			S.push(x->rc);		//���Һ�����ջ
			x = x->lc;
		}
		if (!S.empty())break;	//ֱ��ջ��
		x = S.top();		//������һ�����
		S.pop();
	}
	return output;
}
template <typename T> vector<T> BinTree<T>::Inorder_Traversal(BinNodePosi(T) x) {//�������
	stack<BinNodePosi(T)> S;
	vector<T> output;
	while (true) {
		if (x) {			//�������룬ֱ��û�����ӵĽڵ�
			S.push(x);		//���ڵ��ջ
			x = x->lc;		//�������������
		}else if (!S.empty()) {		
			x = S.top();
			output.push_back(x->data);	
			S.pop();
			x = x->rc;		//����������
		}else
			break;
	}
	return output;
}
template <typename T> vector<T> BinTree<T>::Postorder_Traversal(BinNodePosi(T) x) {//�������
	stack<BinNodePosi(T)> S;
	vector<T> output;
	if (x) S.push(x);
	while (!S.empty()) {
		if (S.top() != x->parent)	//��ջ���ǵ�ǰ�ڵ�֮�����Ϊ������ 
		{	//������ɼ�Ҷ�ڵ� 
			while (BinNodePosi(T) x = S.top()) {
				if (HasLChild(*x)) {
					if (HasRChild(*x))	S.push(x->rc);
					x = x->lc;
				}
				else
					S.push(x->rc);
			}
			S.pop();
		}
		x = S.top();
		S.pop();
		output.push_back(x->data);
	}
	return output;
}
template <typename T> vector<T> BinTree<T>::levelorder_Traversal(BinNodePosi(T) x) {//��α���
	queue<BinNodePosi(T)> Q;
	vector<T> output;
	Q.push(x);
	while (!Q.empty()) {
		Q.pop(x);
		visit();
		if (HasLChild(*x)) Q.push(x->lc);
		if (HasRChild(*x)) Q.push(x->lc);
	}
	return output;
}
