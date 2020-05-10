#include<stdio.h>
#include<stdlib.h>

int partition(int a[], int l,int h)
{
    int pivot = a[l];
    int i=l, j=h;
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);       
    } while (i<j);
    int temp = a[j];
    a[j] = a[l];
    a[l] = temp;
    return j;
}

void QuickSort(int a[], int l, int h)
{
    int j;
    if(l<h)
    {
        j = partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}

int main()
{
    int size;
    printf("Enter the size of elements:\n");
    scanf("%d",&size);
    int a[size+1];
    printf("Enter the elements: \n");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    //Here we need to initialize the last with max so that comparison can be stopped at the worst case when i reaches the end 
    a[size] = 32767;
    printf("Before sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);        
    QuickSort(a,0,size+1);
    printf("\nAfter sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
}