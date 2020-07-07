package DataStructures_Algorithms.DataStructures.Graphs;
//Detecting cycles in Graph
import java.util.*;
public class Graph {
    private final int V;
    private final List<List<Integer>> edges;
    public Graph(int V)
    {
        this.V = V;
        edges = new ArrayList<>(V);
        for(int i=0;i<V;i++)
            edges.add(new LinkedList<>());
    }
    void addEdge(int s, int d)
    {
        edges.get(s).add(d);
    }

    boolean isCyclicHelper(int i, boolean[] visited, boolean[] stack)
    {
        if(stack[i])
            return true;
        if(visited[i])
            return false;
        visited[i] = true;
        stack[i] = true;

        List<Integer> adj = edges.get(i);
        for(Integer el : adj)
        {
            if(isCyclicHelper(el, visited, stack))
                return true;
        }
        //Backtrack
        stack[i] = false;
        return false;
    }

    boolean isCyclic()
    {
        boolean[] visited = new boolean[V];
        boolean[] stack = new boolean[V];

        //Find the cycle in all possible dfs from all vertices
        for(int i=0;i<V;i++)
            if(isCyclicHelper(i, visited, stack))
                return true;
        return false;
    }
    public static void main(String[] args) {
        Graph graph = new Graph(4); 
        graph.addEdge(0, 1); 
        graph.addEdge(0, 2); 
        graph.addEdge(1, 2); 
        graph.addEdge(2, 0); 
        graph.addEdge(2, 3); 
        graph.addEdge(3, 3);         

        if(graph.isCyclic())
            System.out.println("YES");
        else
            System.out.println("NO");            

    }

}