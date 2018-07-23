/*
*Tree
*2018年7月23日 23:03:25 
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
	BinNodePosi(T) insertAsLC(T const&);//作为当前节点的左孩子插入新节点
	BinNodePosi(T) insertAsRC(T const&);//作为当前节点的右孩子插入新节点
	BinNodePosi(T) succ();//取当前节点的直接后继

};
template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e) {
	return  lc = new BinNode(e,*this);
}
template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e) {
	return  rc = new BinNode(e, *this);
}
template<typename T>BinNodePosi(T) BinNode<T>::succ() {
	BinNodePosi(T) s = this;
	if (rc)	//若有右孩子，则直接后继必在右子树中
	{
		s = rc;
		while (HasLChild(*s))	s = s->lc;//最靠左节点
	}
	else//否则，直接后继是“将当前节点包含于其左子树中最低祖先”
	{
		while (IsRChild(*s))	s = s->parent;//逆向地沿右向分支，不断朝左上方移动
		s = s->parent;//最后再朝右上方移动一步，到达直接后继
	}
}
template <typename T> class BinTree {
protected:
	int _size; BinNodePosi(T) _root;
	int updateHeight(BinNodePosi(T) x);//更新节点x的高度
	void updateHeightAbove(BinNodePosi(T) x);//更新高度
public:
	BinTree():_size(0),_root(NULL){}
	BinNodePosi(T) insertAsRoot(T const&e) ;
	BinNodePosi(T) insertAsLc(BinNodePosi(T) x, T const& e) ;//e作为x的左孩子（原无）插入
	BinNodePosi(T) insertAsRc(BinNodePosi(T) x, T const& e) ;//e作为x的右孩子（原无）插入
	BinNodePosi(T) attachAsLc(BinNodePosi(T) x, BinTree<T>* &T) ;//T作为左子树接入
	BinNodePosi(T) attachAsRc(BinNodePosi(T) x, BinTree<T>* &T) ;//T作为右子树接入
	//遍历
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

template <typename T> vector<T> BinTree<T>::Preorder_Traversal(BinNodePosi(T) x) {//先序遍历
	stack<BinNodePosi(T)> S;//辅助栈
	vector<T> output;
	while (true) {
		while (x) {				//不断visit，并不断深入直到最左侧节点
			output.push_back(x->data);		//visit(x);
			S.push(x->rc);		//将右孩子入栈
			x = x->lc;
		}
		if (!S.empty())break;	//直到栈空
		x = S.top();		//弹出下一批起点
		S.pop();
	}
	return output;
}
template <typename T> vector<T> BinTree<T>::Inorder_Traversal(BinNodePosi(T) x) {//中序遍历
	stack<BinNodePosi(T)> S;
	vector<T> output;
	while (true) {
		if (x) {			//不断深入，直到没有左孩子的节点
			S.push(x);		//根节点进栈
			x = x->lc;		//深入遍历左子树
		}else if (!S.empty()) {		
			x = S.top();
			output.push_back(x->data);	
			S.pop();
			x = x->rc;		//遍历右子树
		}else
			break;
	}
	return output;
}
template <typename T> vector<T> BinTree<T>::Postorder_Traversal(BinNodePosi(T) x) {//后序遍历
	stack<BinNodePosi(T)> S;
	vector<T> output;
	if (x) S.push(x);
	while (!S.empty()) {
		if (S.top() != x->parent)	//若栈顶非当前节点之父则必为其右兄 
		{	//最高左侧可见叶节点 
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
template <typename T> vector<T> BinTree<T>::levelorder_Traversal(BinNodePosi(T) x) {//层次遍历
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
