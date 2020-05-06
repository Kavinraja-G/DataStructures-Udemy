#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
    char data;
    struct node *p;
}*top=NULL;

void push(struct node *st, char data)
{
    st = (struct node *)malloc(sizeof(struct node));
    if(st == NULL)
    {
        printf("\nStack is full.\n");
    }
    else
    {
        st->data = data;
        st->p = top;
        top = st;
    }
}

char pop(struct node *st)
{
    st = (struct node *)malloc(sizeof(struct node));
    char data=-1;
    if(top == NULL)
    {    
        printf("\nStack is empty.\n");
    }
    else
    {
        st = top;
        top = top->p;
        data = st->data;
    }
    return data;
}

void display(struct node *st)
{
    st = (struct node *)malloc(sizeof(struct node));
    st = top;
    if(top == NULL)
        printf("Stack is Empty.\n");
    else
    {
        while (st->p!=NULL)
        {
            printf("%c || ",st->data);
            st = st->p;
        }
        printf("%c ",st->data);
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

int checkPrecedence(char a)
{
    //Precedence Table for the Conversion using Stack
    if(a == '+' || a=='-')
        return 1;
    else if(a=='*' || a=='/')
        return 2;
    return 0;
}

int checkVariable(char a)
{
    if(a == '+' || a=='-' || a == '*' || a =='/')
        return 0;
    return 1;
}

int main()
{
    char *s="a+b*c-d/e";
    printf("Entered expression to Convert into PostFix: %s\n",s);
    int i=0,j=0;
    push(top,'#');
    char *post;
    int len = strlen(s);
    post = (char *)malloc((len+2)*sizeof(char));
    while(s[i]!='\0')
    {
        if(checkVariable(s[i]))
            post[j++] = s[i++];
        else
        {
            if(checkPrecedence(s[i]) > checkPrecedence(top->data))
                push(top,s[i++]);
            else
                post[j++] = pop(top);
        }
    }
    while (top!=NULL)
        post[j++] = pop(top);
    post[j]='\0';

    printf("\nPostfix converted Expression: %s",post);
}