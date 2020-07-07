package DataStructures_Algorithms.DataStructures.Queue;
import java.util.*;

public class QueueUsingTwoStacks {
    static Stack<Integer> stack1 = new Stack<>();
    static Stack<Integer> stack2 = new Stack<>();
    static void pushAllFromS1ToS2()
    {
        while(!stack1.isEmpty())
        {
            stack2.push(stack1.pop());
        }
    }
    static void enqueue(int data)
    {
        stack1.push(data);
    }
    static int dequeue()
    {
        if(stack2.isEmpty())
        {
            pushAllFromS1ToS2();
        }
        return stack2.pop();
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int queries = s.nextInt();
        while(queries-- >0)
        {
            int op = s.nextInt();
            if(op == 1)
                enqueue(s.nextInt());
            if(op==2)
                dequeue();
            if(op==3)
            {
                if(stack2.isEmpty())
                    pushAllFromS1ToS2();        
                System.out.println(stack2.peek());
            }
        }
    }    
}