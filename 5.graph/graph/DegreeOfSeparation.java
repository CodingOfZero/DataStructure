package ChapterFour.One;

import java.util.Scanner;
import java.util.Stack;

/**
 * 间隔的度数：使用BFS,符号表实现
 * 问题定义：比如找到一个社交网络中两个人间隔的度数，本人定义为0，直接与本人认识为1，与本人朋友认识为2，以此类推
 */
public class DegreeOfSeparation {
    public static void main(String[] args) {
        SymbolGraph sg=new SymbolGraph("E:/Java/Algorithms/algs4-data/routes.txt"," ");
        Graph G=sg.G();
        Scanner scanner=new Scanner(System.in);
        String source=scanner.nextLine();
        if(!sg.contains(source)){
            System.out.println(source+"not in database.");
            return;
        }

        BreadthFirstPaths bfs=new BreadthFirstPaths(G,sg.index(source));
        while (scanner.hasNextLine()){
            String sink=scanner.nextLine();
            if(sg.contains(sink)){
                int v=sg.index(sink);
                if(bfs.hasPathTo(v)){
                    Stack<Integer> stack = bfs.pathTo(v);
                    while (!stack.isEmpty()){
                        int m=stack.pop();
                        System.out.println(" "+sg.name(m));
                    }
                }else System.out.println(" Not connected");
            }else System.out.println(" Not in database.");
        }
    }
}
