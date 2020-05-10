#include<stdio.h>
#include<stdlib.h>

void shellSort(int a[], int n)
{
    int gap,key,j;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            key = a[i];
            j = i-gap;
            while (j>=0 && a[j]>key)
            {
                a[j+gap] = a[j];
                j = j-gap;
            }
            a[j+gap] = key;
        }
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
    shellSort(a,size);
    printf("\nAfter sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
}