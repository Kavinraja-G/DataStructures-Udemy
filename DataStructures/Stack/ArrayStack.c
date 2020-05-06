#include<stdio.h>
#include<malloc.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->s = (int *)malloc(size * sizeof(int));
}

void push(struct Stack *st, int data)
{
    if(st->top == st->size-1)
        printf("Stack is Full and Overflow.\n");
    else
    {
        st->top++;
        st->s[st->top] = data;
    }
}

int pop(struct Stack *st)
{
    int data = -1;
    if(st->top == -1)
        printf("Stack is Empty.\n");
    else
    {
        data = st->s[st->top];
        st->top--;
    }
    return data;
}

void display(struct Stack *st)
{
    if(st->top == -1)
        printf("Stack is Empty.\n");
    else
    {
        for(int i=st->top; i>=0; i--)
            printf("%d ",st->s[i]);
    }
        
}

int main()
{
    struct Stack *s;
    int c=1;
    int size;
    printf("Enter the size of the Stack:\n");
    scanf("%d",&size);
    create(s,size);
    while (c)
    {
        int op;
        printf("\nEnter the options to perform on Stack:\n 1.To Push\n 2.To Pop\n 3.To Display\n 0. To close\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
        {
            int x;
            printf("\nEnter the data to Push:\n");
            scanf("%d",&x);
            push(s,x);
            break;
        }
        case 2:
            printf("\n%d is popped.\n",pop(s));
            break;
        
        case 3:
            display(s);
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