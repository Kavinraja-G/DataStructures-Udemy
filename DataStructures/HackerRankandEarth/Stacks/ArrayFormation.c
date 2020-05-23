#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

int stack[10000];
int k = -1;
struct queue
{
    int data;
    int front;
    int rear;
    int *Q;
};

void push(int data)
{
    stack[++k] = data;
}

int pop()
{
    return stack[k--];
}

int isEmptyStack()
{
    return (k==-1);
}

void create(struct queue *q,int size)
{
    q->front = -1;
    q->rear = -1;
    q->Q = (int *)malloc(size * sizeof(int));
}

void enqueue(struct queue *q, int data)
{
    q->rear++;
    q->Q[q->rear] = data;
}

int dequeue(struct queue *q)
{
    q->front++;
    return q->Q[q->front];
}

int isEmptyQueue(struct queue *q)
{
    return (q->front == q->rear);
}

void displayQueue(struct queue *q)
{
    while (!isEmptyQueue(q))
    {
        printf("%d ",dequeue(q));
    }   
}

void displayStack()
{
    while (!isEmptyStack())
    {
        printf("%d ",pop());
    }
}

int checkPrime(int v)
{
    int val = ceil(v/2);
    for(int i=2;i<val;i++)
    {
        if(v % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    struct queue *q;
    q = malloc(sizeof(struct queue));
    int n;
    scanf("%d",&n);
    create(q,n);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d",&val);
        if(checkPrime(val))
            enqueue(q,val);
        else
            push(val);
    }
    displayQueue(q);
    printf("\n");
    displayStack();
    
}