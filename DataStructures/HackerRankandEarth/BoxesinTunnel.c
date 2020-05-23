#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int l,w,h;
        scanf("%d %d %d",&l,&w,&h);
        if(h<41)
        {
            printf("%d\n",(l*w*h));
        }
    }
}