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
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int data)
{
    if((q->rear+1)%q->size == q->front)
        printf("Circular Queue is Full.\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q)
{
    int data = -1;
    if(q->front == q->rear)
        printf("Circular Queue is Empty.\n");
    else
    {
        q->front = (q->front+1)%q->size;
        data = q->Q[q->front];
    }
    return data;
}

void display(struct Queue *q)
{
    int i = q->front+1;
    if(q->front == q->rear)
        printf("\nCircular Queue is Empty.\n");
    do
    {
        printf("%d ",q->Q[i]);
        i = (i+1)%q->size; // Move in similar like the rear and front so itteration is possible
    } while (i!= (q->rear+1)%q->size);
    printf("\n");
}

int main()
{
    struct Queue *q;
    int c=1;
    int size;
    printf("Enter the size of the Circular Queue:\n");
    scanf("%d",&size);
    create(q,size);
    while (c)
    {
        int op;
        printf("\nEnter the options to perform on Circular Queue:\n 1.To Enqueue\n 2.To Dequeue\n 3.To Display\n 0. To close\n");
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