typedef enum{UNDISCOVERED,DISCOVERED,VISITED}VStatus;//����״̬
typedef enum{UNDETERMINED,TREE,CROSS,FORWARD,BACKWARD}Etype;//���ڱ���������������
#include<stack>
#include<queue>
using std::queue;
using std::stack;
template<typename Tv,typename Te>
class Graph {
private:
	void reset() {//���ж��㡢�ߵĸ�����Ϣ��λ
		for (int i = 0; i < n; i++) {//���ж���
			status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;//״̬��ʱ���ǩ
			parent(i) = -1; priority(i) = INT_MAX;
			for (int j = 0; j < n; j++)//���бߵ�
				if (exists(i, j))type(i, j) = UNDETERMINED;
		}
	}
	void BFS(int, int &);//���
	void DFS(int, int &);//���
	bool TSort(int, int&, stack<Tv>*);//����DFS����������
public:
	//��
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
	//��
	int e;
	virtual bool exists(int,int) = 0;
	virtual void insert(Te const& ,int,int,int) = 0;
	virtual Te remove(int,int) = 0;
	virtual Etype& type(int,int) = 0;
	virtual Te& edge(int,int) = 0;
	virtual int& weight(int,int) = 0;
	//�㷨
	void bfs(int);
	void dfs(int);
	stack<Tv>* tSort(int);
	void prim(int);
	void dijkstra(int);
};
//������������㷨(ȫͼ)
template <typename Tv,typename Te> void Graph<Tv,Te>::bfs(int s) {
	reset(); int clock = 0; int v = s;
	do
		if (status(v) == UNDISCOVERED)
			BFS(v, clock);
	while (s != (v = (++v%n)));//����ż�飬�ʲ�©����;
}
//������ͨ��
template<typename Tv, typename Te>void Graph<Tv, Te>::BFS(int v, int& clock) {
	queue<int> Q;
	status(v) = DISCOVERED;	Q.push(v);//��ʼ�����
	while (!Q.empty()) {//��Q���֮ǰ������ȡ�����׶���v
		int v = Q.front(); Q.pop(); dTime(v) = ++clock;
		for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))//ö��v�������ھ�
		{
			if (status(u) == UNDISCOVERED)//��u��δ����
			{
				status(u) = DISCOVERED; Q.push(u);
				type(v, u) = TREE; parent(u) = v;
			}
			else//��u�ѱ����֣������ѷ�����ϣ�����v,u����Ϊ���
				type(v, u) = CROSS;
		}
		status(v) = VISITED;//���ˣ���ǰ����������
	}
}
//������������㷨(ȫͼ)   O(n+e)
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
			case UNDISCOVERED://u��δ������
				type(v, u) = TREE; parent(u) = v; DFS(u, clock); break;
			case DISCOVERED://u�ѱ����ֵ���δ������ϣ�Ӧ�������ָ�������
				type(v, u) = BACKWARD; break;
			default://u�ѷ������(VISITED,����ͼ)�����ӳ�Ϯ��ϵ��Ϊǰ��߻���
				type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS; break;
		}
	}
	status(v) = VISITED;
	fTime(v) = ++clock;
}
