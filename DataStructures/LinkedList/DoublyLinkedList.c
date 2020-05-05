#include<stdio.h>
#include<malloc.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
}*head=NULL;


void display(struct node *t)
{
    while(t->next != NULL)
    {
        printf("%d -->",t->data);
        t = t->next;
    }
}

void insert(struct node *p,int index,int val)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    if(head == NULL)
    {
        head = new;
        head->prev = NULL;
        head->next = NULL;
    }
    else
    {
        p = (struct node *)malloc(sizeof(struct node));
        p = head;
        if(index == 0)
        {
            new->next = head;
            new->prev = NULL;
            head->prev = new;
            head = new;
        }
        else
        {
            for(int i=0;i<index-1;i++)
                p = p->next;
            new->next = p->next;
            new->prev = p;
            p->next->prev = new;
            p->next = new;
        }
    }
}

int delete(struct node *p,int index)
{
    int data;
    if(index == 0)
    {
        p = head;
        data = p->data;
        p = p->next;
        p->prev = NULL;
        head = p;
    }
    else
    {
        p = head;
        for(int i=0;i<index-1;i++)
            p=p->next;
        data = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = NULL;
        p->prev = NULL;
    }
    return data;
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->next = NULL;
    int op = 1;
    while (op)
    {
        printf("\nEnter the following operations to perform: \n 1. To Insert\n 2. To delete\n 3. To Display\n 0. To Exit\n");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {   int val=0,index=0;
            printf("Enter the data and index to Insert:\n");
            scanf("%d %d",&index,&val);
            insert(head,index,val);
            break;
        }

        case 2:
        {
            int index;
            printf("Enter the index to Delete:\n");
            scanf("%d",&index);
            printf("Deleted Data: %d\n",delete(head,index));
            break;
        }

        case 3:
            printf("Displaying the Doubly Linked List: \n");
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