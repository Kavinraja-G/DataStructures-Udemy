#include<stdio.h>

unsigned long long int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1); 
    
}

int main()
{
    unsigned long long int n=5;
    printf("Factorial of %lld is %lld",n,fact(n));
}