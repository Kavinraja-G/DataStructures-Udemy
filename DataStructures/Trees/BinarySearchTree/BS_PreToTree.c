#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node 
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

struct stack 
{
    int size;
    int top;
    struct node **S;
}*s=NULL;

void create(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct node **)malloc(st->size * sizeof(struct node *));
}

void push(struct stack *st,struct node *data)
{
    st->top++;
    st->S[st->top] = data;
}

struct node * pop(struct stack *st)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = 32767;
    t->left = NULL; t->right = NULL;
    if(st->top == -1)
        return t;
    else
    {
        t = st->S[st->top];
        st->top--;
    }
    return t;
}

int getTop(struct stack *st)
{
    if(st->top == -1)
        return 32767;
    else
    {
        return st->S[st->top]->data;
    }
}

void createBST(int A[], int n)
{
    int i=0;
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    create(s,n);
    struct node *t,*p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = A[i++];
    p->left = NULL; p->right = NULL;
    root = p;
    while (i < n)
    {
        if(A[i] < p->data)
        {
            //For left node Insertion => Push the parent Address!
            t = (struct node *)malloc(sizeof(struct node));
            t->left = NULL; t->right = NULL;
            t->data = A[i++];
            p->left = t;
            push(s,p);
            p = t;
        }
        else
        {
            //For Right node insertion => Don't push! Just check with the top
            if((A[i]>p->data) && A[i] < getTop(s))
            {
                t = (struct node *)malloc(sizeof(struct node));
                t->left = NULL; t->right = NULL;
                t->data = A[i++]; 
                p->right = t;        
                p = t;       
            }
            else
            {
                //If the new node is not between the parent and the previous parent
                //Then pop out the previous parent node and store in 'p'  
                p = pop(s);
            }
        }
        
    }
}

void displayBST(struct node *t)
{
    if(t)
    {
        displayBST(t->left);
        printf("%d ",t->data);
        displayBST(t->right);
    }
}

int main()
{
    root = (struct node *)malloc(sizeof(struct node));
    int A[] = {30,20,10,15,25,40,50,45};
    createBST(A,8);
    displayBST(root);
}