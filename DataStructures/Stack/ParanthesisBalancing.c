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
    int data = 0;
    if(st == NULL)
    {    
        return data;
    }
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

int isEmpty(struct node *t)
{
    t = top;
    if (t==NULL)
        return 0;
    else 
        return 1;
}

int main()
{
    struct node *top;
    top = (struct node *)malloc(sizeof(struct node));
    char *s;
    s = (char *)malloc(100 * sizeof(char));
    printf("Enter the string to Analyse:\n");
    scanf("%s",s);
    int i=0,last,flag=0;
    while(s[i] != '\n')
    {
        if(s[i] == '(' )
            push(top,1);
        else if(s[i] == ')')
        {   
            if(isEmpty(top)==0)
            {
                last = pop(top);
                flag = 1;
            } 
            else
                last = pop(top);
        }
        i++;
    }
    if(isEmpty(top)==1)
        printf("\nParanthesis not balanced.\n");
    else if(isEmpty(top)==0 && flag==1)
        printf("\nParanthesis are not Balanced.\n");    
    else
        printf("\nParanthesis are Balanced.\n");
}