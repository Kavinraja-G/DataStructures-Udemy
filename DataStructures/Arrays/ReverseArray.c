#include<stdio.h>
int main()
{
    int a[] = {2,4,5,6};
    int length = 4;
    //Here we swap the end most elements to mid
    for(int i=0,j=length-1;i<j;i++,j--)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    for(int i=0;i<length;i++)
        printf("%d ",a[i]);
}