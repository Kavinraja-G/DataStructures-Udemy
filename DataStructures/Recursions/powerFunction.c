#include<stdio.h>

/* int power(int m,int n)
{
    if(n==0)
        return 1;
    return power(m,n-1)*m;
} */

//More faster way of calculating the power recursively:
int power(int m,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return power(m*m , n/2);
    else
        return m* power(m*m, (n-1)/2);
}

int main()
{
        int m=2,n=16;
        printf("%d",power(m,n));
}