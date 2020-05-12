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
void bfs(int A[][7], int s, int n)
{
    int u,v;
    int visit[7] = {0};
    printf("%d ",s);
    visit[s] = 1;
    enqueue(s);
    while (!isEmpty())
    {
        u = dequeue();
        for(v=1;v<=n;v++)
        {
            if(A[u][v] == 0 && visit[v]!=1)
            {
                printf("%d ",v);
                visit[v] = 1;
                enqueue(v);
            }
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
 bfs(G,4,7);
}