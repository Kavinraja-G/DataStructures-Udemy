#include<stdio.h>
#include<malloc.h>

struct node 
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));

    if(t == NULL)
        printf("Heap is Full.\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    struct node *p;
    int x=-1;
    if(front == NULL)
        printf("Queue is Empty.\n");
    else
    {
        p = front;
        x = front->data;
        front = front->next;
        free(p);
    }
    return x;
}

int isEmpty()
{
    return front==NULL;
}
void dfs(int A[][7], int s, int n)
{
    static int visit[7] = {0};
    if(visit[s]==0)
    {
        printf("%d ",s);
        visit[s] = 1;
        for(int j=1;j<n;j++)
        {
            if(A[s][j]==1 && visit[j]==0)
                dfs(A,j,n);
        }
    }
}

int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
 {0,0,1,1,0,0,0},
 {0,1,0,0,1,0,0},
 {0,1,0,0,1,0,0},
 {0,0,1,1,0,1,1},
 {0,0,0,0,1,0,0},
 {0,0,0,0,1,0,0}};
 dfs(G,1,7);
}