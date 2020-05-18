package ChapterFour.Two;

import java.util.Stack;

/**
 * 拓扑排序：
 *          1. 判断是否为DAG
 *          2. 是的情况下，逆后序
 */
public class Topological {
    private Stack<Integer> order;

    public Topological(Digraph G){
        DirectedCycle cyclefinder=new DirectedCycle(G);
        if(!cyclefinder.hasCycle()){
            DepthFirstOrder dfs=new DepthFirstOrder(G);
            order=dfs.reversePost();
        }
    }
    public Stack<Integer> order(){return order;}
    public boolean isDAG(){return order!=null;}

    public static void main(String[] args) {
        SymbolDigraph sg=new SymbolDigraph("E:/Java/Algorithms/algs4-data/jobs.txt","/");
        Digraph G=sg.G();
        Topological top=new Topological(G);
        Stack<Integer> order = top.order();
        while (!order.isEmpty()){
            System.out.println(sg.name(order.pop()));
        }

    }
}
