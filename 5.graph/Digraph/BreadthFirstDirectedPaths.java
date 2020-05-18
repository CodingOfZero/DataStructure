package ChapterFour.Two;
/**
 * 单点最短有向路径:只需将无向图中BreadthFirstPaths算法中的Graph替换为Digraph
 * 输入一个点，求出它到所有点的最短距离
 */

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class BreadthFirstDirectedPaths {
    private boolean[] marked;
    private int[] edgeTo;
    private int s;
    public BreadthFirstDirectedPaths(Digraph G,int s){
        this.s=s;
        marked=new boolean[G.V()];
        edgeTo=new int[G.V()];
        bfs(G,s);
    }
    private void bfs(Digraph G,int s){
        Queue<Integer> queue=new LinkedList<>();
        queue.add(s);
        marked[s]=true;
        while(!queue.isEmpty()){
            int v=queue.poll();
            for(int x:G.adj(v))
                if(!marked[x]){
                    queue.add(x);
                    edgeTo[x]=v;
                    marked[x]=true;
                }
        }
    }
    public boolean hasPathTo(int v){return marked[v];}
    public Stack<Integer> pathTo(int v){
        if(!marked[v]) return null;
        Stack<Integer> path=new Stack<>();
        for(int x=v;x!=s;x=edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }


    public static void main(String[] args) {
        String filename="E:/Java/Algorithms/algs4-data/tinyDG.txt";
        Digraph G=new Digraph(filename);
        Scanner scanner=new Scanner(System.in);
        int s=scanner.nextInt();

        BreadthFirstDirectedPaths paths=new BreadthFirstDirectedPaths(G,s);

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
