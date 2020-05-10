#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int l, int mid, int h)
{
    int b[100];
    int i=l,j=mid+1;
    int k=l;

    while (i<=mid && j<=h)
    {
        if(a[i]<a[j])
            b[k++] = a[i++];
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

void mergeSort(int a[],int n)
{
    int p,l,h,mid;
    for(p=2; p<n;p*=2)
    {
        for(int i=0; (i+p-1)<n; i+=p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(a,l,mid,h);
        }
    }
    //In case if the size is of an odd number
    if(p/2 <n)
        merge(a,0,p/2 - 1,n-1);
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
    mergeSort(a,size);
    printf("\nAfter sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
}
