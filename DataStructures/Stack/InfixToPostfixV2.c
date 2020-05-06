#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node 
{
    char data;
    struct node *next;
}*top=NULL;

void push(int data)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if(t == NULL)
        printf("Heap is Full\n");
    else
    {
        t->data = data;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    char x = -1;
    if(top == NULL)
        printf("\nStack is Empty.\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
    }
    return x;
}

int checkoutPrecedence(char a)
{
    if(a=='+' || a=='-')
        return 1;
    else if(a=='*' || a=='/')
        return 3;
    else if(a=='^')
        return 6;
    else if(a=='(')
        return 7;
    else
        return 0;
}

int checkinPrecedence(char a)
{
    if(a=='+' || a=='-')
        return 2;
    else if(a=='*' || a=='/')
        return 4;
    else if(a=='^')
        return 5;
    else if(a=='(' || a==')')
        return 0;
    else
        return 0;
}

int isVariable(char a)
{
    if(a=='+' || a=='-' || a=='*' || a=='/' || a=='(' || a==')' || a=='^')
        return 0;
    return 1;
}

int main()
{
    char *s = "((a+b)*c)-d^e^f";
    int len = strlen(s);
    char *post;
    post = (char *)malloc((len+2)*sizeof(char));
    int i=0,j=0;
    push('|');
    printf("\n%s\n",s);
    while(s[i]!='\0')
    {
        if(isVariable(s[i])==1)
            post[j++] = s[i++];
        else
        {
            if(checkoutPrecedence(s[i]) > checkinPrecedence(top->data))
                push(s[i++]);
            else if(checkoutPrecedence(s[i]) < checkinPrecedence(top->data))
            {
                post[j++] = pop();
            }
            else
            {
                pop();
                i++; //For closing Braces
            }
        }
    }
    while (top!=NULL)
    {
        post[j++] = pop();
    }
    post[j] = '\0';
    printf("\nPostifix Expression: %s",post);

}
