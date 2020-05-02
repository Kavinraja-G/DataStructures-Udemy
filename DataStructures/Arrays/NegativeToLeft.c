//Program to bring the -ve numbers to the left and +ve to the right

#include<stdio.h>
int main()
{
    int a[] = {-1,2,-5,5,7,8,-8};
    int l = 7;
    int i=0,j=l-1;
    while (i<j)
    {
        while(a[i]<0) i++;
        while(a[j]>0) j--;
        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    for ( i = 0; i < l; i++)
        printf("%d ",a[i]);
    
    

}