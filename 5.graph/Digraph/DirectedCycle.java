package ChapterFour.Two;

import java.util.Stack;

/**
 * 寻找有向环
 */
public class DirectedCycle {
    private boolean[] marked;
    private int[] edgeTo;
    private Stack<Integer> cycle;//存放有向环中的所有顶点
    private boolean[] onStack;//递归调用的栈上的所有顶点

    public DirectedCycle(Digraph G){
        onStack=new boolean[G.V()];
        marked=new boolean[G.V()];
        edgeTo=new int[G.V()];
        for(int s=0;s<G.V();s++){
            if(!marked[s])
                dfs(G,s,s);
        }
    }
    private void dfs(Digraph G,int v,int u){
        onStack[v]=true;
        marked[v]=true;
        for(int w:G.adj(v))
            if(this.hasCycle()) return;
            else if(!marked[w]){
                edgeTo[w]=v;
                dfs(G,w,v);
            }else if(onStack[w]){//w!=v这种错误，原因？
                cycle=new Stack<Integer>();
                for(int x=v;x!=w;x=edgeTo[x])
                    cycle.push(x);
                cycle.push(w);
                cycle.push(v);
            }
        onStack[v]=false;
    }

    public boolean hasCycle(){
        return cycle!=null;
    }
    public Iterable<Integer> cycle(){return cycle;}

    public static void main(String[] args) {
        String filename="E:/Java/Algorithms/algs4-data/tinyDG.txt";
        Digraph G=new Digraph(filename);


        DirectedCycle cycle=new DirectedCycle(G);
        if(cycle.hasCycle()){
            Iterable<Integer> cycle1 = cycle.cycle();
            for (int x:cycle1)
                System.out.print(x+" ");
        }else
            System.out.println("no paths");

    }
}
