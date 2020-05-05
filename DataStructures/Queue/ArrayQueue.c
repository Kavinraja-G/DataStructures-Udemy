#include<stdio.h>
#include<malloc.h>

struct Queue
{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct Queue *q,int size)
{
    q->front = -1;
    q->rear = -1;
    q->Q = (int *)malloc(size * sizeof(int));
}

void enqueue(struct Queue *q, int data)
{
    if(q->rear == q->size-1)
        printf("Queue is Full.\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q)
{
    int data = -1;
    if(q->front == q->rear)
        printf("Queue is Empty.\n");
    else
    {
        q->front++;
        data = q->Q[q->front];
    }
    return data;
}

void display(struct Queue *q)
{
    if(q->front == q->rear)
        printf("\nQueue is Empty.\n");
    if(q->rear == q->size-1)
        printf("\nQueue is Full.\n");
    for(int i=q->front+1 ;i<=q->rear ;i++)
    {
        printf("%d ",q->Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue *q;
    int c=1;
    int size;
    printf("Enter the size of the Queue:\n");
    scanf("%d",&size);
    create(q,size);
    while (c)
    {
        int op;
        printf("\nEnter the options to perform on Queue:\n 1.To Enqueue\n 2.To Dequeue\n 3.To Display\n 0. To close\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
        {
            int x;
            printf("\nEnter the data to be enqueued:\n");
            scanf("%d",&x);
            enqueue(q,x);
            break;
        }
        case 2:
            printf("\n%d is deleted.\n",dequeue(q));
            break;
        
        case 3:
            display(q);
            break;
        
        case 0:
            c = 0;
            break;
        default:
            printf("\nEnter a valid option.\n");
            break;
        }
    }
}