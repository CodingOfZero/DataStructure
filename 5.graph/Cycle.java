package ChapterFour.One;

import java.util.Scanner;
import java.util.Stack;

/**
 * 判断是否为无环图
 * API:
 *      Cycle(Graph G)
 *      void dfs(Graph G,int v,int u)
 *      boolean hasCycle()
 */
public class Cycle {
    private boolean[] marked;
    private boolean hasCycle;
    public Cycle(Graph G){
        marked=new boolean[G.V()];
        for(int s=0;s<G.V();s++){
            if(!marked[s])
                dfs(G,s,s);
        }
    }
    private void dfs(Graph G,int v,int u){
        marked[v]=true;
        for(int w:G.adj(v))
            if(!marked[w]){
                dfs(G,w,v);
            }else if(w!=v)
                hasCycle=true;
    }

    public boolean hasCycle(){
        return hasCycle;
    }


    public static void main(String[] args) {
        String filename="E:/Java/Algorithms/algs4-data/tinyCG.txt";
        Graph G=new Graph(filename);


        Cycle cycle=new Cycle(G);
        System.out.println(cycle.hasCycle());
    }

}
