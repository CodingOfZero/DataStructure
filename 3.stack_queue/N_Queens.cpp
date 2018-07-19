/*
*N_Quenns
*2018年7月18日 21:57:58 
*/
#include<iostream>
#include<stack>
#include<vector>
using std::stack;using std::vector;
struct Queen{
	int x,y;
	Queen(int xx, int yy){
		x=xx;
		y=yy;
	}
	bool operator ==(Queen const &q) const{					//重载相等运算符以此判定是否冲突 
		return (y==q.y)||(x+y==q.x+q.y)||(x-y==q.x-q.y);	//同一列以及对角线； 
	}
	bool operator !=(Queen const &q) const{return !(*this==q);}
};
template <typename T>
class Stack_1{						//利用vector实现了一个栈，可以进行find操作； 
public:
	vector<T> temp;
	int find(T const& e){			//用来判定是否发生冲突 
		for(size_t i=0;i!=temp.size();++i)	//不要使用temp.size()-1这种操作，易下标越界（size为0时） 
		{
			if(e==temp[i])
				return i;
		}
		return -1;
	}
	void push(T const& e){temp.push_back(e);}
	T &top(){ return temp.back();}
	void pop(){temp.pop_back();}
	int size(){return temp.size();}
	bool empty(){return temp.empty();}
	
}; 
int placeQueens(int N){
	Stack_1<Queen> solu;
	Queen q(0,0);
	int nSolu=0;
	do{//反复试探回溯 
		if(N<=solu.size()||N<=q.y)		//若已出界或已形成一个全局解时 
		{
			q=solu.top();				//回溯，并继续试探下一列 
			solu.pop();
			q.y++;
		}else
		{
			while((q.y<N)&&(!solu.empty())&&(0<=solu.find(q)))	//比对已有皇后 
			{
				q.y++;					//发生冲突，移到下一列 
			}
			if(N>q.y)					//若存在可摆放的列 
			{
				solu.push(q);
				if(N<=solu.size())		//若部分解成为全局解，则通过全局变量计数 
					nSolu++;
				q.x++;					//移到下一行开头 
				q.y=0;
			}
		}
	}while(0<q.x||q.y<N);				//所有分支均已剪枝之后，算法结束 
	return nSolu;
}
int main(){
	std::cout<<placeQueens(8);
	return 0;
}
/*

/*
*N_Quenns
*2018年7月19日 15:49:41 
*Input: 4
*Output: [
	 [".Q..",  // Solution 1
	  "...Q",
	  "Q...",
	  "..Q."],
	
	 ["..Q.",  // Solution 2
	  "Q...",
	  "...Q",
	  ".Q.."]
*	]

#include<iostream>
#include<stack>
#include<vector>
#include<string>
using std::stack;using std::vector; using std::string;using std::cout;
struct Queen{
	int x,y;
	Queen(int xx, int yy){
		x=xx;
		y=yy;
	}
	bool operator ==(Queen const &q) const{					//重载相等运算符以此判定是否冲突 
		return (y==q.y)||(x+y==q.x+q.y)||(x-y==q.x-q.y);	//同一列以及对角线； 
	}
	bool operator !=(Queen const &q) const{return !(*this==q);}
};
template <typename T>
class Stack_1{						//利用vector实现了一个栈，可以进行find操作； 
public:
	vector<T> temp;
	int find(T const& e){			//用来判定是否发生冲突 
		for(size_t i=0;i!=temp.size();++i)	//不要使用temp.size()-1这种操作，易下标越界（size为0时） 
		{
			if(e==temp[i])
				return i;
		}
		return -1;
	}
	void push(T const& e){temp.push_back(e);}
	T &top(){ return temp.back();}
	void pop(){temp.pop_back();}
	int size(){return temp.size();}
	bool empty(){return temp.empty();}
}; 
vector<vector<string> > placeQueens(int N){
	Stack_1<Queen> solu;
	Queen q(0,0);
	Queen print_q(0,0);
	int nSolu=0;
	
	vector<vector<string> > pt;		//存放最终结果 
	vector <string> s1,s1_copy,L,R,com;		//定义一个向量及其副本，初始化向量 

	string s2;
	char Q='Q';
	char point='.';
	for(int x=0;x<N;++x)
		s2.push_back(point);
	for(int y=0;y<N;++y)
	{
		s1.push_back(s2);	
	}
	s1_copy=s1;

	do{//反复试探回溯 
		if(N<=solu.size()||N<=q.y)		//若已出界或已形成一个全局解时 
		{
			q=solu.top();				//回溯，并继续试探下一列 
			solu.pop();
			q.y++;
		}else
		{
			while((q.y<N)&&(!solu.empty())&&(0<=solu.find(q)))	//比对已有皇后 
			{
				q.y++;					//发生冲突，移到下一列 
			}
			if(N>q.y)					//若存在可摆放的列 
			{
				solu.push(q);
				if(N<=solu.size())		//若部分解成为全局解，则通过全局变量计数 
				{
				//	nSolu++;
					for(size_t j=0;j!=solu.temp.size();++j)
					{
						print_q=solu.temp[j];
						s1[print_q.x][print_q.y]=Q;
					}
					pt.push_back(s1);
					s1=s1_copy;
				}	
				q.x++;					//移到下一行开头 
				q.y=0;
			}
		}
	}while(0<q.x||q.y<N);				//所有分支均已剪枝之后，算法结束 
	return pt;
	//	return nSolu;
}
int main(){
	vector<vector<string> > pt=placeQueens(4);
	for(vector<vector<string> >::iterator it_pt=pt.begin();it_pt!=pt.end();++it_pt)	//输出结果 
	{
		cout<<"[";
		for(size_t i=0;i<(*it_pt).size();++i)
		{
			if(i==0)
			{
				cout<<"\"";
				cout<<(*it_pt)[i];
				cout<<"\"";
			}else
			{
				cout<<","<<"\"";
				cout<<(*it_pt)[i];
				cout<<"\"";
			}	
		}
			
		cout<<"]";
	}
	return 0;
}
*/ 
