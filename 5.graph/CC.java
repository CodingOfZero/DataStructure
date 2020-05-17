package ChapterFour.One;

import java.util.Scanner;
import java.util.Stack;

/**
 * 连通分量
 * API：
 *      CC(Graph G)
 *      boolean connected(int v,int w) //v与w是否相通
 *      int count()//连通分量数
 *      int id(int v)//v所在的连通分量的标识符（0~count()-1）
 */
public class CC {
    private boolean[] marked;
    private int count;
    private int[] id;
    public CC(Graph G){
        marked=new boolean[G.V()];
        id=new int[G.V()];
        for(int s=0;s<G.V();s++){
            if(!marked[s]){
                dfs(G,s);
                count++;
            }
        }
    }
    private void dfs(Graph G, int v) {
        marked[v]=true;
        id[v]=count;//连通标识符
        for(int w:G.adj(v))
            if(!marked[w]){
                dfs(G,w);
            }
    }
    public boolean connected(int v,int w){return id[v]==id[w];} //v与w是否相通
    public int count(){return count;}//连通分量数
    public int id(int v){return id[v];}//v所在的连通分量的标识符（0~count()-1）
    public static void main(String[] args) {
        String filename="E:/Java/Algorithms/algs4-data/tinyG.txt";
        Graph G=new Graph(filename);

        CC cc=new CC(G);
        System.out.println(cc.count);
        System.out.println(cc.connected(0,5));
        System.out.println(cc.connected(0,9));
        System.out.println(cc.id(0));
    }
}
