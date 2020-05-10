#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    int height;
    struct node *right;
}*root=NULL;

int heightNode(struct node *t)
{
    int hl,hr;
    hl = (t && t->left) ? t->left->height : 0;
    hr = (t && t->right) ? t->right->height : 0;

    return hl>hr?hl+1:hr+1;
}

int balanceFactor(struct node *t)
{
    int hl,hr;
    hl = (t && t->left) ? t->left->height : 0;
    hr = (t && t->right) ? t->right->height : 0;    
    
    return hl-hr;
}

struct node * LLrotation(struct node *p)
{
    struct node *pl=p->left,*plr=pl->right;
    pl->right = p;
    p->left = plr;
    p->height = heightNode(p);
    pl->height = heightNode(pl);
    if(root == p)
        root = pl;
    return pl;
}

struct node * LRrotation(struct node *p)
{
    struct node *pl=p->left;
    struct node *plr=pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;

    //Height must be assigned in this order
    pl->height = heightNode(pl);
    p->height = heightNode(p);
    plr->height = heightNode(plr);

    if(root = p)
        root = plr;

    return plr;
}

struct node * insert(struct node *p, int key)
{
    struct node *t=NULL;
    if(p==NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->left = NULL;
        t->right = NULL;
        t->height = 1;
        return t;
    }
    if(key < p->data)
        p->left = insert(p->left, key);
    else if(key>p->data)
        p->right = insert(p->right, key);
    //At the return change the height
    p->height = heightNode(p);

    if(balanceFactor(p)==2 && balanceFactor(p->left)==1)
        return LLrotation(p);
    if(balanceFactor(p)==2 && balanceFactor(p->left)==-1)
        return LRrotation(p);
    return p;
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
    root = insert(root,50);
    insert(root,10);
    insert(root,20);
    inOrder(root);
}