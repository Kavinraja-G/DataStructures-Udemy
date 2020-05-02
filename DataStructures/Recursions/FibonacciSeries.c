//Program to find the fibonacci number of the nth term
#include<stdio.h>

/* int fib(int n)
{
    if(n<=1)
        return n;
    else
        return fib(n-1) + fib(n-2);
} */

/* Usually the above funtion results in the O(2n) complexity and it is also called as the Excessice Recursion
We go for the memoization function by storing the results in the array and checking at each call if it's exists then
we use it in the function without calling so the time reduces by the below method. */

int a[10];
int fib(int n)
{
    if(n<=1)
    {
        a[n] = n;
        return n;
    }
    else
    {
        if(a[n-2] == -1) 
            a[n-2] = fib(n-2);
        if(a[n-1] == -1)
            a[n-1] = fib(n-1);

        return a[n-2]+a[n-1];
    }
    
}

int main()
{
    int n;
    for(int i=0;i<10;i++)
        a[i] = -1;
    printf("%d",fib(10));
}