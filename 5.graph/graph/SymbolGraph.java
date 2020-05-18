package ChapterFour.One;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

/**
 * 符号图：文件格式为边的集合，顶点和边的个数隐式定义
 * 用到的数据结构：
 *              符号表,键的类型为String，值的类型为int(索引)
 *              数组keys[]，用作反向索引，保存每个顶点索引所对应的顶点名
 *              图：使用索引来引用图中顶点
 * API:
 *      SymbolGraph(String filename,String delim)//根据filename指定的文件构造图，使用delim来分隔顶点名
 *      boolean contains(String key)//key是一个顶点吗？
 *      int index(String key)//key的索引
 *      String name(int v)//索引v的顶点名
 *      Graph G()//隐藏的Graph对象
 */
public class SymbolGraph {
    private HashMap<String,Integer> st;
    private String[] keys;
    private Graph G;
    public SymbolGraph(String filename,String delim){
        //第一次读取文件
        st=new HashMap<>();
        File file=new File(filename);
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()){
                String[] a=scanner.nextLine().split(delim);
                for(int i=0;i<a.length;i++)//为每个不同字符串关联一个索引
                    if(!st.containsKey(a[i]))
                        st.put(a[i],st.size());
            }
            keys=new String[st.size()];//用作反向索引
            for(String name:st.keySet())
                keys[st.get(name)]=name;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        //第二次构造图
        try {
            G=new Graph(st.size());
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()){
                String[] a=scanner.nextLine().split(delim);
                int v=st.get(a[0]);
                for(int i=1;i<a.length;i++)//为每个不同字符串关联一个索引
                    G.addEdge(v,st.get(a[i]));
            }
            keys=new String[st.size()];//用作反向索引
            for(String name:st.keySet())
                keys[st.get(name)]=name;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }//根据filename指定的文件构造图，使用delim来分隔顶点名

    public boolean contains(String s){ return st.containsKey(s); }//key是一个顶点吗？
    public int index(String s){ return st.get(s);}//key的索引
    public String name(int v){ return keys[v];}//索引v的顶点名
    public Graph G(){return G;}//隐藏的Graph对象

    public static void main(String[] args) {
        SymbolGraph graph=new SymbolGraph("E:/Java/Algorithms/algs4-data/movies.txt","/");
        Graph G=graph.G();
        Scanner scanner=new Scanner(System.in);
        while (scanner.hasNextLine()){
            String source=scanner.nextLine();
            for(int w:G.adj(graph.index(source)))
                System.out.println(" "+graph.name(w));
        }

    }
}
