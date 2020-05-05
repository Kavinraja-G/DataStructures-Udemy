#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//Self-referential structure:
struct node 
{
    int data;
    struct node *p; //Here p refers to the pointer pointing the next node
}*head;

//Creating Linked List using arrays:
/* void create(int a[],int size)
{
    struct node *last,*t;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->p = NULL;
    last = head;
    for(int i=1;i<size;i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->p = NULL;
        last->p = t;
        last = t;
    }
} */

void display(struct node *t)
{
    while (t!=NULL)
    {
        printf("%d ",t->data);
        t=t->p;
    }
}

void insert(struct node *head,int index,int val)
{
    struct node *tail,*new,*curr;
    tail = (struct node *)malloc(sizeof(struct node));
    new = (struct node *)malloc(sizeof(struct node));
    tail->p=NULL;
    curr=head;
    new->data = val;
    new->p = NULL;
    if(index == 0)
    {
        head->data = new->data;
        head->p = NULL;
        curr = head;
    }
    else
    {
        for(int i=0;i<index;i++)
        {
            tail = curr;
            curr =curr->p;
        }
        new->p = curr;
        tail->p = new;
    }  
}

void delete(struct node *curr, int data)
{
    struct node *tail;
    if(curr->data == head->data) //Special case for handling head
    {
        tail = head;
        head = head->p;
        free(tail);
    }   
    else
    {
        struct node *prev;
        prev = (struct node *)malloc(sizeof(struct node));
        prev->p = NULL;
        while (curr->data != data && curr->p!=NULL)
        {   
            prev = curr;
            curr=curr->p;
        }
        if(curr->data == data)
            prev->p = curr->p;
    }
            
}



int main()
{
    int index,data;
    head = (struct node *)malloc(sizeof(struct node));
    head->p = NULL;
    int op = 1;
    while (op)
    {
        printf("Enter the node and data to insert:\n");
        scanf("%d %d",&index,&data);
        insert(head,index,data);
        printf("\n1 to continue 0 to close\n");
        scanf("%d",&op);
    }
    printf("\nDisplaying LinkedList:\n");
    display(head);
    printf("\nAfter Deletion in LinkedList:\n");
    delete(head,3);
    display(head);
}