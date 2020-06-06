#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *S;
}*st=NULL;

void create(int size)
{
    st->top = 0;
    st->size = size;
    st->S = (char *)malloc(st->size * sizeof(char));    
}

void push(char data)
{
    st->top++;
    st->S[st->top] = data;
}

char pop()
{
    char data;
    data = st->S[st->top];
    st->S[st->top] = '\0';
    st->top--;
    return data;
}

int isEmpty()
{
    return (st->top == 0);
}

int main()
{

    int test;
    scanf("%d",&test);

    while (test-- >0) 
    {
        int flag = 0;
        st = (struct stack *)malloc(sizeof(struct stack));
        create(1002);
        char *str;
        str = (char *)malloc(1002 * sizeof(char));
        scanf("%s",str);
        int len = strlen(str);
        if(str[0]==')' || str[0]==']' || str[0]=='}')
        {
            flag = 1;
            printf("NO\n");
            continue;
        }
        for (int i=0; i<len; i++) 
        {
            if(str[i]=='(' || str[i]=='[' || str[i]=='{')
                push(str[i]);
            else if (str[i]==')' || str[i]==']' || str[i]=='}') 
            {
                char TOP = st->S[st->top];
                if(str[i] == ')')
                {
                    if(TOP=='(')
                        pop();
                    else
                    {
                        flag = 1;
                        printf("NO\n");
                        break;
                    }
                }
                else if(str[i] == ']')
                {
                    if(TOP=='[')
                        pop();               
                    else
                    {
                        flag = 1;
                        printf("NO\n");
                        break;
                    }
                }
                else if(str[i] == '}')
                {
                    if(TOP=='{')
                        pop();               
                    else
                    {
                        flag = 1;
                        printf("NO\n");
                        break;
                    }
                }
            }
        }
        if(flag==0)
        {
            if(isEmpty())
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
