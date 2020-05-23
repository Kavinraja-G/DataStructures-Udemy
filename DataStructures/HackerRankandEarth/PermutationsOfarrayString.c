#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void permutate(char s[][10], int k, int n)
{
    static int a[9]={0};
    static int res[9]={0};
    if(k == n-1)
    {
        for(int i=0;i<n;i++)
            printf("%d ",res[i]);
        printf("\n");
    }
    else
    {  
        for(int i=0; i<n;i++)
        {
            if(a[i]==0)
            {
                res[k] = i;
                a[i] = 1;
                permutate(s,k+1,n);
                a[i] = 0;
            }
        }
    }
    
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[n][10];
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    permutate(s,0,n);
}