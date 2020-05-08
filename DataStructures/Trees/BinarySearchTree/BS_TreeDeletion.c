#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

void insert(struct node *t,int key)
{
    struct node *r,*p;
    if(root == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->left = NULL;
        p->right = NULL;
        root = p;
        return;
    }
    while (t!=NULL)
    {
        r = t;
        if(key < t->data)
            t = t->left;
        else if(key > t->data)
            t = t->right;
        else
            return;
    }
    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->left = NULL;
    p->right = NULL;
    if(key<r->data)
        r->left = p;
    else
        r->right = p;
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

int height(struct node *t)
{
    int x,y;
    if (t==NULL)
    {
        return 0;
    }
    x = height(t->left);
    y = height(t->right);
    return x>y?x+1:y+1;
}

struct node * inorderPredecessor(struct node *t)
{
    while (t && t->right!=NULL)
        t=t->right;
    return t;
}

struct node * inorderSuccessor(struct node *t)
{
    while (t && t->left!=NULL)
        t=t->left;
    return t;
}

struct node * delete(struct node *t, int key)
{
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        return NULL;
    if(t->left==NULL && t->right==NULL)
    {
        if(t == root)
            root =NULL;
        free(t);
        return NULL;
    }   
    if(key< t->data)
        t->left = delete(t->left,key);
    else if(key > t->data)
        t->right = delete(t->right,key);
    else
    {
        if(height(t->left) > height(t->right))
        {
            q = inorderPredecessor(t->left);
            t->data = q->data;
            t->left = delete(t->left, q->data); // Here we need to replace the deleted place with other predecessor 
        }
        if(height(t->left) < height(t->right))
        {
            q = inorderSuccessor(t->right);
            t->data = q->data;
            t->right = delete(t->right, q->data); // Here we need to replace the deleted place with other successor 
        }        
    }
    return t;
}


int main()
{
    insert(root,10);
    insert(root,5);
    insert(root,20);
    insert(root,30);
    insert(root,25);
    delete(root,20);
    inOrder(root);

}