#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void countSort(int a[], int n)
{
    int max=0;
    //Checking for max:
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    //Initializing with the max element size of the given array
    int *count = (int *)malloc((max+1) * sizeof(int));
    for(int i=0;i<=max;i++)
        count[i] = 0;
    //CountSorting...
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    //Restoring the sorted values in the given array
    int i=0,j=0;
    while(i<max+1)
    {
        if(count[i]>0)
        {
            a[j++] = i;
            count[i]--;
        }
        else
            i++;
    }
}


int main()
{
    int size;
    printf("Enter the size of elements:\n");
    scanf("%d",&size);
    int a[size];
    printf("Enter the elements: \n");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    printf("Before sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);        
    countSort(a,size);
    printf("\nAfter sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");    
}