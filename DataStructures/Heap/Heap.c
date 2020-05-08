#include<stdio.h>
#include<stdlib.h>
void insert(int a[], int n)
{
    int temp,i=n;
    temp = a[i];
    while (i>1 && temp>a[i/2]) // Move to the parent node until temp is lesser
    {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = temp;
}

int main()
{
    int a[] = {0,10,20,70,100,45,15};
    for(int i=2;i<7;i++)
    {
        insert(a,i); //Inserting the array elements in the max_heap order
    }
    printf("Heap Elements: ");
    for(int i=0;i<7;i++)
        printf("%d ",a[i]);
}