#include<stdio.h>
#include<stdlib.h>
int swaps = 0;
void merge(int a[], int l, int mid, int h)
{
    int b[100];
    int i=l,j=mid+1;
    int k=l;

    while (i<=mid && j<=h)
    {
        if(a[i]<=a[j])
        {    
            b[k++] = a[i++];
            swaps += mid+1-i;
        }
        else
            b[k++] = a[j++];
    }
    for(;i<=mid;i++)
        b[k++] = a[i];
    for(;j<=h;j++)
        b[k++] = a[j];
    for(int i=l;i<=h;i++)
        a[i] = b[i];
}

void mergeSort(int a[],int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
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
    mergeSort(a,0,size-1);
    printf("\nAfter sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("Swaps in sorting: %d",swaps);
    printf("\n");
}
