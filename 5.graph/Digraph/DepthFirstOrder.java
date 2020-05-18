package ChapterFour.Two;


import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * 有向图中基于深度优先搜索的顶点排序
 * API:
 *      Iterable<Integer> pre()//前序：在递归调用之前将顶点加入队列
 *      Iterable<Integer> post()//后序：在递归调用之后将顶点加入队列
 *      Iterable<Integer> reversePost()//逆后序，在递归调用之后将顶点加入栈（即为拓扑顺序的一种）
 */
public class DepthFirstOrder {
    private boolean[] marked;
    private Queue<Integer> pre;
    private Queue<Integer> post;
    private Stack<Integer> reversePost;
    public DepthFirstOrder(Digraph G){
        pre=new LinkedList<>();
        post=new LinkedList<>();
        reversePost=new Stack<>();

        marked=new boolean[G.V()];
        for(int v=0;v<G.V();v++)
            if(!marked[v])
                dfs(G,v);
    }
    private void dfs(Digraph G,int v){
        pre.add(v);
        marked[v]=true;
        for(int w:G.adj(v))
            if(!marked[w])
                dfs(G,w);
        post.add(v);
        reversePost.push(v);
    }
    public Iterable<Integer> pre(){return pre;}
    public Iterable<Integer> post(){return post;}
    public Stack<Integer> reversePost(){return reversePost;}

    public static void main(String[] args) {
        String filename="E:/Java/Algorithms/algs4-data/tinyDG.txt";
        Digraph G=new Digraph(filename);
        DepthFirstOrder order=new DepthFirstOrder(G);
        Iterable<Integer> pre = order.pre();
        Iterable<Integer> post = order.post();
        Stack<Integer> reversePos = order.reversePost();
        System.out.print("pre: ");
        for (int x:pre) System.out.print(x+" ");

        System.out.println();
        System.out.print("post: ");
        for (int x:post) System.out.print(x+" ");

        System.out.println();
        System.out.print("reversePos: ");
        while (!reversePos.isEmpty()){
            System.out.print(reversePos.pop()+" ");
        }
    }
}
