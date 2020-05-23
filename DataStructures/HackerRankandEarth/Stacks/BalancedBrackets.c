#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
char s[100000];
int z = -1;
void emptyStack()
{
    while (z== -1)  
    {
        z--;
    }
}
int isEmpty()
{
    return(z == -1);
}
void push(char data)
{
    s[++z] = data;
}
void pop()
{
    s[z] = '\0';
    z--;
}
char peek()
{
    return s[z];
}
int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        char *str;
        str = (char *)malloc(1000 * sizeof(char));
        scanf("%s",str);
        int i=0;
        int flag=0,pushCount=0,popCount=0;
        for(int i=0;i<strlen(str);i++)
        {
            while (str[i]=='(' || str[i]=='[' || str[i]=='{')
            {
                pushCount++;
                push(str[i]);
                break;
            }
            while((str[i]==')' && peek()=='(')||(str[i]==']' && peek()=='[')||(str[i]=='}' && peek()=='{'))
            {
                popCount++;
                pop();
                break;
            }
        }
        if(pushCount != popCount) 
            printf("NO\n");
        else 
            printf("YES\n");
        n--;
        char s[100000];
        z = -1;
    }
}