#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

struct Queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
}*q=NULL;

void create(struct Queue *q,int size)
{
    q->size = size;
    q->rear =0; 
    q->front=0;
    q->Q = (struct node **)malloc(q->size*sizeof(struct node *));
}

void enqueue(struct Queue *q, struct node *x)
{
    if((q->rear+1)%q->size == q->front)
        printf("\nQueue is Full\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

struct node * dequeue(struct Queue *q)
{
    struct node *data = NULL;
    if(q->rear == q->front)
        printf("\nEmpty Queue!.\n");
    else
    {
        q->front = (q->front+1)%q->size;
        data = q->Q[q->front];
    }
    return data;
}

int isEmpty(struct Queue *q)
{
    if(q->front == q->rear)
        return 1;
    return 0;
}

void createTree()
{
    q = (struct Queue *)malloc(sizeof(struct Queue));
    create(q,100);
    struct node *p,*t;
    int x;
    printf("\nEnter the root value:\n");
    scanf("%d",&x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->left = NULL; root->right =NULL;
    enqueue(q,root);
    while (!isEmpty(q))
    {
        p = dequeue(q);
        printf("\nEnter the Left Child:\n");
        scanf("%d",&x);
        if(x!= -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->left = t;
            enqueue(q,t);
        }
        printf("\nEnter the Right Child:\n");
        scanf("%d",&x);
        if(x!= -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->right = t;
            enqueue(q,t);
        }
    }
}

void preOrder(struct node *t)
{
    if(t)
    {
        printf("%d ",t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void postOrder(struct node *t)
{
    if(t)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ",t->data);
    }
}

void inOrder(struct node *t)
{
    if(t)
    {
        inOrder(t->left);
        printf("%d ",t->data);
        inOrder(t->right);
    }
}

int main()
{
    createTree();
    printf("\nPre-Order traversal: ");
    preOrder(root);
    printf("\nPost-Order traversal: ");
    postOrder(root);
    printf("\nIn-Order traversal: ");
    inOrder(root);
}