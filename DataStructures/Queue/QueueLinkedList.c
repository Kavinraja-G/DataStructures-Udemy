#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *p;
}*head;

void display(struct node *t)
{
    t = (struct node *)malloc(sizeof(struct node));
    t = head;
    if(head == NULL)
        printf("\nQueue is Empty.\n");
    else
    {
        while (t->p !=NULL)
        {
            printf("%d => ",t->data);
            t = t->p;
        }
        printf("%d\n",t->data);
    }
}

void insert(struct node *t, int val)
{
    struct node *new;
    t = (struct node *)malloc(sizeof(struct node));
    t = head;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->p = NULL;
    if(head == NULL)
    {
        head = new;
        head->p = NULL;
    }
    else
    {
        while (t->p != NULL)
            t=t->p;
        t->p = new;
        t = new;
        t->p = NULL;
    }
}

int delete(struct node *front)
{
    int x = -1;
    if(head == NULL)
        printf("\nQueue is Empty.\n");
    else
    {
        front = head;
        x = front->data;
        head = head->p;
    }
    return x;
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->p = NULL;
    int op = 1;
    while (op)
    {
        printf("\nEnter the following operations to perform on Queue: \n 1. To Insert\n 2. To delete\n 3. To Display\n 0. To Exit\n");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {   int val=0,index=0;
            printf("Enter the data to Insert:\n");
            scanf("%d",&val);
            insert(head,val);
            break;
        }

        case 2:
        {
            printf("Deleted Data: %d\n",delete(head));
            break;
        }

        case 3:
            printf("Displaying the Queue: \n");
            display(head);
            break;

        case 0: 
            op=0;
            break;

        default:
            printf("Enter a valid option...\n");
            break;
        }
    }
}