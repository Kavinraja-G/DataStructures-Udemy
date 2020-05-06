#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *p;
}*top;

void push(struct node *st, int data)
{
    st = (struct node *)malloc(sizeof(struct node));
    st->data = data;
    st->p = NULL;
    if(top == NULL)
    {
        top = st;
        top->p = NULL;
    }
    else
    {
        st->p = top;
        top = st;
    }
}

int pop(struct node *st)
{
    st = top;
    int data = -1;
    if(st == NULL)
        printf("Stack is Empty.\n");
    else
    {
        data = st->data;
        st = st->p;
        top = st;
    }
    return data;
}

void display(struct node *st)
{
    st = top;
    if(st == NULL)
        printf("Stack is Empty.\n");
    else
    {
        while (st->p!=NULL)
        {
            printf("%d || ",st->data);
            st = st->p;
        }
        printf("%d ",st->data);
    }
}

int main()
{
    struct node *top;
    top = (struct node *)malloc(sizeof(struct node));
    int c=1;
    while (c)
    {
        int op;
        printf("\nEnter the options to perform on Linked Stack:\n 1.To Push\n 2.To Pop\n 3.To Display\n 0. To close\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
        {
            int x;
            printf("\nEnter the data to Push:\n");
            scanf("%d",&x);
            push(top,x);
            break;
        }
        case 2:
            printf("\n%d is popped.\n",pop(top));
            break;
        
        case 3:
            display(top);
            break;
        
        case 0:
            c = 0;
            break;
        default:
            printf("\nEnter a valid option.\n");
            break;
        }
    }    
}