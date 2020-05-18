package ChapterFour.Two;

/**
 * 有向图的可达性
 * API:
 *      DirectedDFS(Digraph G,int s)////在G中找到从S可达的所有顶点
 *      DirectedDFS(Digraph G,Iterable<Integer> sources)//在G中找到从sources中的所有顶点可达的所有顶点
 *      boolean marked(int v)//v是否可达
 */
public class DirectedDFS {
    private boolean[] marked;
    public DirectedDFS(Digraph G,int s){
        marked=new boolean[G.V()];
        dfs(G,s);
    }
    public DirectedDFS(Digraph G,Iterable<Integer> sources){
        marked=new boolean[G.V()];
        for(int s:sources)
            if(!marked[s])
                dfs(G,s);
    }
    public boolean marked(int v){return marked[v];}
    private void dfs(Digraph G,int v){
        marked[v]=true;
        for(int w:G.adj(v))
            if(!marked[w])
                dfs(G,w);
    }

    public static void main(String[] args) {
        Digraph G=new Digraph("E:/Java/Algorithms/algs4-data/tinyDG.txt");
        DirectedDFS dfs=new DirectedDFS(G,2);
        for(int v=0;v<G.V();v++)
            if(dfs.marked(v))
                System.out.println(v+" ");
    }
}
