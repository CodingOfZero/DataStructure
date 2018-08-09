typedef enum{UNDISCOVERED,DISCOVERED,VISITED}VStatus;//顶点状态
typedef enum{UNDETERMINED,TREE,CROSS,FORWARD,BACKWARD}Etype;//边在遍历树中所属类型
#include<stack>
#include<queue>
using std::queue;
using std::stack;
template<typename Tv,typename Te>
class Graph {
private:
	void reset() {//所有顶点、边的辅助信息复位
		for (int i = 0; i < n; i++) {//所有顶点
			status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;//状态、时间标签
			parent(i) = -1; priority(i) = INT_MAX;
			for (int j = 0; j < n; j++)//所有边的
				if (exists(i, j))type(i, j) = UNDETERMINED;
		}
	}
	void BFS(int, int &);//广度
	void DFS(int, int &);//深度
	bool TSort(int, int&, stack<Tv>*);//基于DFS的拓扑排序
public:
	//点
	int n;
	virtual int insert(Tv const&) = 0;
	virtual Tv remove(int) = 0;
	virtual int inDegree(int) = 0;
	virtual int outDegree(int) = 0;
	virtual int firstNbr(int) = 0;
	virtual int nextNbr(int,int) = 0;
	virtual VStatus& status(int) = 0;
	virtual int& dTime(int) = 0;
	virtual int& fTime(int) = 0;
	virtual int& parent(int) = 0;
	virtual int& priority(int) = 0;
	//边
	int e;
	virtual bool exists(int,int) = 0;
	virtual void insert(Te const& ,int,int,int) = 0;
	virtual Te remove(int,int) = 0;
	virtual Etype& type(int,int) = 0;
	virtual Te& edge(int,int) = 0;
	virtual int& weight(int,int) = 0;
	//算法
	void bfs(int);
	void dfs(int);
	stack<Tv>* tSort(int);
	void prim(int);
	void dijkstra(int);
};
//广度优先搜索算法(全图)
template <typename Tv,typename Te> void Graph<Tv,Te>::bfs(int s) {
	reset(); int clock = 0; int v = s;
	do
		if (status(v) == UNDISCOVERED)
			BFS(v, clock);
	while (s != (v = (++v%n)));//按序号检查，故不漏不重;
}
//单个连通域
template<typename Tv, typename Te>void Graph<Tv, Te>::BFS(int v, int& clock) {
	queue<int> Q;
	status(v) = DISCOVERED;	Q.push(v);//初始化起点
	while (!Q.empty()) {//在Q变空之前，不断取出队首顶点v
		int v = Q.front(); Q.pop(); dTime(v) = ++clock;
		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))//枚举v的所有邻居
		{
			if (status(u) == UNDISCOVERED)//若u尚未发现
			{
				status(u) = DISCOVERED; Q.push(u);
				type(v, u) = TREE; parent(u) = v;
			}
			else//若u已被发现，或者已访问完毕，将（v,u）归为跨边
				type(v, u) = CROSS;
		}
		status(v) = VISITED;//至此，当前顶点访问完毕
	}
}
//深度优先搜索算法(全图)   O(n+e)
template<typename Tv, typename Te> void Graph<Tv, Te>::dfs(int s) {
	reset(); int clock = 0; int v = s;
	do
		if (status(v) == UNDISCOVERED)
			DFS(v, clock);
	while (s != (v = ++v%n));
}
template<typename Tv, typename Te>void Graph<Tv, Te>::DFS(int v, int& clock) {
	dTime(v) = ++clock; status(v) = DISCOVERED;
	for (int u=firstNbr(v);-1<u;u=nextNbr(v,u)) 
	{
		switch (status(u))
		{
			case UNDISCOVERED://u尚未被发现
				type(v, u) = TREE; parent(u) = v; DFS(u, clock); break;
			case DISCOVERED://u已被发现但尚未访问完毕，应属被后代指向的祖先
				type(v, u) = BACKWARD; break;
			default://u已访问完毕(VISITED,有向图)，则视承袭关系分为前向边或跨边
				type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS; break;
		}
	}
	status(v) = VISITED;
	fTime(v) = ++clock;
}
