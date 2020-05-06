#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{               
    int data;
    struct node *next;
}*top=NULL;

void push(int data)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if(t == NULL)
        printf("Heap has been overflow!.\n");
    else
    {
        t->data = data;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x = 0;
    struct node *t;
    t = top;
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        x = t->data;
        top = top->next;
        free(t);
    }
    return x;
}

int checkVar(char a)
{
    if(a=='+' ||a=='-' ||a=='*' ||a=='/' ||a=='^')
        return 0;
    return 1;
}

int main()
{
    char *post = "35*62/+4-";
    int l,r,i=0;
    for(int i=0;post[i]!='\0';i++)
    {
        if(checkVar(post[i]))
            push(post[i]-'0'); //Used for the conversion of char to respective numbers
        else
        {
            r = pop(); l = pop();
            switch (post[i])
            {
            case '+':
                push(l+r);
                break;
            case '-':
                push(l-r);
                break;
            case '*':
                push(l*r);
                break;
            case '/':
                push(l/r);
                break;            
            default:
                break;
            }
        }
    }
    printf("Result : %d\n",pop());
    
}