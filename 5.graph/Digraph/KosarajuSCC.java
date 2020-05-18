package ChapterFour.Two;

import java.util.Stack;

/**
 * 计算强连通分量：
 *              1.求得给定图的反向图
 *              2.使用DepthFirstOrder计算反向图的逆后序排列
 *              3.在G中进行标准深度优先遍历，按照步骤2所得的顺序访问所有未标记的顶点
 * API：
 *      KosarajuSCC(Digraph G)
 *      boolean connected(int v,int w) //v与w是否相通
 *      int count()//连通分量数
 *      int id(int v)//v所在的连通分量的标识符（0~count()-1）
 */
public class KosarajuSCC {
    private boolean[] marked;
    private int[] id;
    private int count;
    private int V;
    public KosarajuSCC(Digraph G){
        V=G.V();
        marked=new boolean[G.V()];
        id=new int[G.V()];
        DepthFirstOrder order=new DepthFirstOrder(G.reverse());
        Stack<Integer> stack = order.reversePost();
        while (!stack.isEmpty()){
            int s = stack.pop();
            if(!marked[s]){
                dfs(G,s);
                count++;
            }
        }
    }
    private void dfs(Digraph G,int v){
        marked[v]=true;
        id[v]=count;
        for(int w:G.adj(v))
            if(!marked[w])
                dfs(G,w);
    }
    public boolean stronglyConnected(int v,int w){ return id[v]==id[w];}
    public int count(){return count;}
    public int id(int v){return id[v];}
//    public String toString(){
//        StringBuilder sb=new StringBuilder();
//        sb.append(count).append(" components\n");
//        for(int i=0;i<count;i++){
//            for(int j=0;j<V;j++){
//                if(id[j]==i)
//                    sb.append(j).append(" ");
//            }
//            sb.append("\n");
//        }
//        return sb.toString();
//    }
    public static void main(String[] args) {
        String filename="E:/Java/Algorithms/algs4-data/tinyDG.txt";
        Digraph G=new Digraph(filename);
        KosarajuSCC kscc=new KosarajuSCC(G);
        //System.out.println(kscc.count+" components");
        System.out.println(kscc);
    }
}
