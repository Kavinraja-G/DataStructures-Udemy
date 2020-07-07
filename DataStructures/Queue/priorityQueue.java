package DataStructures_Algorithms.DataStructures.Queue;

import java.util.*;

class modifiedComparator implements Comparator<String>
{
    @Override
    public int compare(String s1, String s2)
    {
        return s2.compareTo(s1);
    }
}

public class priorityQueue
{
    public static void main(String[] args)
    {
        PriorityQueue<String> queue = new PriorityQueue<>(new modifiedComparator());
        
        queue.add("G"); 
        queue.add("E"); 
        queue.add("V"); 
        queue.add("I"); 
        queue.add("N"); 
        queue.add("1");
        System.out.println("Based on Lexographical order:");
        while(!queue.isEmpty())
            System.out.print(queue.poll()+" ");
    }
}