#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
	} else {     
		struct node* cur;		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
		return root;
	}
}

struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
}*q=NULL;

void create(struct queue *q)
{
    q->size = 500;
    q->front = -1;
    q->rear = -1;
    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
}

void insertQueue(struct queue *q, struct node *t)
{
    if(q->rear > 500)
        printf("Queue is Full");
    else 
    {
        q->rear+=1;
        q->Q[q->rear] = t;   
    }
}

struct node * access(struct queue *q)
{
    struct node *t = NULL;
    if(q->front == q->rear)
        return t;
    else 
    {
        q->front+=1;
        t = q->Q[q->front];
    }
    return t;
}

int isEmpty(struct queue *q)
{
    return q->front == q->rear;
}

void levelOrder( struct node *root) {
    q = (struct queue *)malloc(sizeof(struct queue));
    create(q);
    insertQueue(q, root);
    while (!isEmpty(q)) 
    {
        struct node *t;
        t =  (struct node *)malloc(sizeof(struct node));
        t = access(q);
        if(t->left!=NULL)
            insertQueue(q, t->left);
        if(t->right!=NULL)
            insertQueue(q, t->right);
        printf("%d ",t->data);
    }
}


int main() {
    struct node* root = NULL;
    int t;
    int data;
    scanf("%d", &t);
    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
	levelOrder(root);
    return 0;
}
