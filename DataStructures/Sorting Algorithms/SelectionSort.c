#include<stdio.h>
#include<stdlib.h>

void selectionSort(int a[], int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(a[j]<a[k])
                k = j;    
        }
        //Swapping between A[i] and A[k]
        int temp = a[k];
        a[k] = a[i];
        a[i] = temp;
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
    selectionSort(a,size);
    printf("\nAfter sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
}