package ChapterFour.Two;

import java.util.Scanner;
import java.util.Stack;

/**
 * 单点有向路径：只需将无向图中DepthFirstPaths算法中的Graph替换为Digraph
 * 输入一个点，求出它到所有点的路径（若存在）
 */
public class DepthFirstDirectedPaths {
    private boolean[] marked;//标记这个顶点遍历过没有
    private int[] edgeTo;//从起点到一个顶点的已知路径上的最后一个顶点,一颗由父链接表示的树
    private final int s;//起点

    public DepthFirstDirectedPaths(Digraph G,int s){
        this.s=s;
        marked=new boolean[G.V()];
        edgeTo=new int[G.V()];
        dfs(G,s);
    }

    private void dfs(Digraph G, int v) {
        marked[v]=true;
        for(int w:G.adj(v))
            if(!marked[w]){
                edgeTo[w]=v;
                dfs(G,w);
            }
    }
    public boolean hasPathTo(int v){return marked[v];}
    public Stack<Integer> pathTo(int v){
        if(!marked[v]) return null;
        Stack<Integer> path=new Stack<>();
        for(int i=v;i!=s;i=edgeTo[i])//先前写为i=edgeTo[]v,导致爆栈
            path.push(i);
        path.push(s);
        return path;
    }

    public static void main(String[] args) {
        String filename="E:/Java/Algorithms/algs4-data/tinyDG.txt";
        Digraph G=new Digraph(filename);
        Scanner scanner=new Scanner(System.in);
        int s=scanner.nextInt();

        DepthFirstDirectedPaths paths=new DepthFirstDirectedPaths(G,s);

        for(int v=0;v<G.V();v++){
            System.out.print(s+" to "+v+":");
            Stack<Integer> path=paths.pathTo(v);
            if(paths.hasPathTo(v)){
                while(!path.isEmpty()){
                    int x=path.pop();
                    if(x==s) System.out.print(x);
                    else System.out.print("-"+x);
                }
            }
            System.out.println();
        }
    }

}
