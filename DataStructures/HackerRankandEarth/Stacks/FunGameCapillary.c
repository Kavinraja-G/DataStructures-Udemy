#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
    long int n;
    scanf("%ld",&n);
    long long int a[n];
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    int A = 0, B = n-1;
    while (A<=n-1 && B>=0)
    {
        if(a[A]>a[B])
        {    
            printf("1 ");
            B--;
        }
        else if(a[B]>a[A])
        {
            printf("2 ");
            A++;
        }
        else
        {
            printf("0 ");
            A++;B--;
        }
    }
    
}