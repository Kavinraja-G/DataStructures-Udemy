#include<stdio.h>
#include<stdlib.h>

int sum(int n)
{
    if(n==0)
        return 0;
    else{
        return sum(n-1)+n; //Tail_type recursive function
    }
}

int main()
{
    int n = 15;
    printf("%d",sum(n));
}