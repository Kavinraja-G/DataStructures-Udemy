#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

struct queue
{
    int front;
    int size;
    int rear;
    struct node **Q; //Array of the node pointers
}*q=NULL;

void create(struct queue *q,int size)
{
    q->rear = 0;
    q->front = 0;
    q->size = size;
    q->Q = (struct node **)malloc(q->size*sizeof(struct node *));
}

void enqueue(struct queue *q, struct node *data)
{
    if((q->rear+1)%q->size == q->front)
        printf("Queue is full in heap memory.\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = data;
    }
}

struct node * dequeue(struct queue *q)
{
    struct node *data=NULL;
    if(q->rear == q->front)
        printf("Queue is empty.\n");
    else
    {
        q->front = (q->front+1)%q->size;
        data = q->Q[q->front];
    }
    return data;
}

int isEmpty(struct queue *q)
{
    return (q->front == q->rear);
}

void createTree()
{
    struct node *p,*t;
    q = (struct queue *)malloc(sizeof(struct queue));
    create(q,100);
    root = (struct node *)malloc(sizeof(struct node));
    root->left =NULL;root->right =NULL;
    int x;
    printf("Enter the root data => \n");
    scanf("%d",&x);
    root->data = x;
    enqueue(q,root);
    while (!isEmpty(q))
    {
        p = dequeue(q);
        printf("Enter the left node of %d => ",p->data);
        scanf("%d",&x);
        if(x!=-1) //-1 to indicate that there is no node
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->left =NULL;
            t->right= NULL;
            p->left = t;
            enqueue(q,t);
        }
        printf("Enter the right node of %d => ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->left =NULL;
            t->right= NULL;
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

int count(struct node *t)
{
    if(t)
        return (count(t->left) + count(t->right) + 1);
    return 0;
}

int height(struct node *t)
{
    int x=0,y=0;
    if(t==0)
        return 0;
    x = height(t->left);
    y = height(t->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}
//To count the no.of leaf nodes in tree
int leaf(struct node *t)
{
    if(t==NULL)
        return 0;
    if(!t->left && !t->right)
        return leaf(t->left)+leaf(t->right)+1;
    else
        return leaf(t->left)+leaf(t->right); 
}

int main()
{
    createTree();
    printf("Preorder Traversal in Tree:\n");
    preOrder(root);
    printf("\nNo of Nodes in the Tree: %d",count(root));
    printf("\nHeight of the Tree: %d",height(root));
    printf("\nNo of leaf Nodes: %d\n",leaf(root));
    
}