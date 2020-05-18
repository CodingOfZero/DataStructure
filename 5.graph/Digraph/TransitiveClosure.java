package ChapterFour.Two;

/**
 * 有向图的可达性与强连通问题有很大区别。
 * 顶点对的可达性：无法应用于大规模有向图
 *          思路：TransitiveClosure通过计算G的传递闭包来支持常数时间的查询--传递闭包矩阵中的第v行就是
 *               TransitiveClosure类中的DirectedDFS[]数组的第v个元素的marked数组
 */
public class TransitiveClosure {
    private DirectedDFS[] all;//单点和多点的可达性
    TransitiveClosure(Digraph G){
        all=new DirectedDFS[G.V()];
        for(int v=0;v<G.V();v++)
            all[v]=new DirectedDFS(G,v);
    }
    public boolean reachable(int v,int w){return all[v].marked(w);}
}
