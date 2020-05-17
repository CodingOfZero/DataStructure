package ChapterFour.One;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

/**
 * 广度优先遍历,最短路径问题
 * API：
 *      BreadthFirstPaths()
 *      void bfs(Graph G,int s)
 *      boolean hasPathTo(int v)
 *      Iterable<Integer> pathTo(int v)
 */
public class BreadthFirstPaths {
       private boolean[] marked;
       private int[] edgeTo;
       private int s;
       public BreadthFirstPaths(Graph G,int s){
           this.s=s;
           marked=new boolean[G.V()];
           edgeTo=new int[G.V()];
           bfs(G,s);
       }
       private void bfs(Graph G,int s){
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
        String filename="E:/Java/Algorithms/algs4-data/tinyCG.txt";
        Graph G=new Graph(filename);
        Scanner scanner=new Scanner(System.in);
        int s=scanner.nextInt();

        BreadthFirstPaths paths=new BreadthFirstPaths(G,s);

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
