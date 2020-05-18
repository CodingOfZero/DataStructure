package ChapterFour.One;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * API:
 *      Graph(int V)                //创建一个含有V个顶点但不含边的图
 *      Graph(String filename)     //根据filename指定的文件构造图
 *      int V()//顶点数
 *      int E()//边数
 *      int addEdge(int v,int w)//加一条v-w的边
 *      int adj(int v)//v相邻的所有顶点
 *      String toString()//对象的字符串表示
 */
public class Graph {
       private int V; //顶点数
       private int E;//边数
       private LinkedList[] adj;//邻接表

       public Graph(int V){
           this.V=V;this.E=0;
           adj= new LinkedList[V];
           for(int v=0;v<V;v++)
               adj[v]=new LinkedList<Integer>();
       }//创建一个含有V个顶点但不含边的图

       public Graph(String filename){
           File file=new File(filename);
           try {
               Scanner scanner = new Scanner(file);
               //顶点
               this.V=scanner.nextInt();
               if (V < 0) throw new IllegalArgumentException("number of vertices in a Graph must be nonnegative");
               adj= new LinkedList[V];
               for(int v=0;v<V;v++)
                   adj[v]=new LinkedList<Integer>();
               //边
               int E=scanner.nextInt();
               for(int i=0;i<E;i++) {
                   int v=scanner.nextInt();
                   int w=scanner.nextInt();
                   validateVertex(v);
                   validateVertex(w);
                   addEdge(v,w);
               }
           } catch (FileNotFoundException e) {
               e.printStackTrace();
           }
       }//根据filename指定的文件构造图

       public int V(){return V;}//顶点数
       public int E(){return E;}//边数
       public void addEdge(int v, int w){
           adj[v].add(w);
           adj[w].add(v);
           E++;
       }//加一条v-w的边
       public Iterable<Integer> adj(int v){
           return adj[v];
       }//v相邻的所有顶点
        private void validateVertex(int v) {
            if (v < 0 || v >= V)
                throw new IllegalArgumentException("vertex " + v + " is not between 0 and " + (V-1));
        }
       public String toString(){
           StringBuilder s= new StringBuilder(V + " vertices, " + E + " edges\n");
           for(int v=0;v<V;v++){
               s.append(v).append(": ");
               for(int w:this.adj(v))
                   s.append(w).append(" ");
               s.append("\n");
           }
           return s.toString();
       }//对象的字符串表示

        public static void main(String[] args) {
            Graph graph=new Graph("E:/Java/Algorithms/algs4-data/tinyCG.txt");
            System.out.println(graph);
            System.out.println(graph.V());
        }
}
