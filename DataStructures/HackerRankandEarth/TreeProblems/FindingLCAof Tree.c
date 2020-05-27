#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node 
{
    struct node *left;
    int data;
    struct node *right;
};

/* struct Queue
{
    int size;
    int rear;
    int front;
    struct node **Q;
}*q=NULL;

void create(struct Queue *q, int size)
{
    q->front = 0;
    q->rear = 0;
    q->size = size;
    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
}

void enqueue(struct Queue *q, struct node *new)
{
    if(((q->rear+1)%q->size) == q->front)
        printf("Queue is Full\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = new;
    } 
}

struct node * dequeue(struct Queue *q)
{
    struct node *data = NULL;
    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front+1)%q->size;
        data = q->Q[q->front];
    }
    return data;
} */
/* 
int isEmpty(struct Queue *q)
{
    return (q->front == q->rear);
} */

struct node * insert(struct node *root, int data)
{
    if(root == NULL)
    {
        struct node *n = (struct node*)malloc(sizeof(struct node));
        n->data = data;
        n->left = NULL;
        n->right = NULL;
        return n;
    }else
    {
        struct node *c;
        if(data<=root->data)
        {
            c = insert(root->left, data);
            root->left = c;
        }else
        {
            c = insert(root->right, data);
            root->right = c;
        }
    }
    return root;
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

struct node * findLowestCommonAncestor(struct node *root, int v1, int v2)
{
    if(root->data<v1 && root->data<v2)
        return findLowestCommonAncestor(root->right,v1,v2);
    if(root->data>v1 && root->data>v2)
        return findLowestCommonAncestor(root->left,v1,v2);
    return root;
}

int main()
{
    struct node *root = NULL,*lca=NULL;
    int v1,v2;
    int size;
    int data;
    scanf("%d",&size);
    while (size-- >0)
    {
        scanf("%d",&data);
        root = insert(root,data);
    }
    scanf("%d %d",&v1,&v2);
    lca = findLowestCommonAncestor(root,v1,v2);
    //preOrder(root);
    printf("\nLCA: %d",lca->data);
}