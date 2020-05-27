#include <stdio.h>
#include <stdlib.h>
/* void merge(int a[], long int l, long int mid, long int h)
{
    int b[h];
    long int i=l,j=mid+1;
    long int k=l;

    while (i<=mid && j<=h)
    {
        if(a[i]<=a[j])
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

void mergeSort(int a[],long int l, long int h)
{
    long int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
} */
void countSort(int a[],long int l, long int h)
{
    int max=0;
    //Checking for max:
    for(int i=l;i<=h;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    //Initializing with the max element size of the given array
    int *count = (int *)malloc((max+1) * sizeof(int));
    for(int i=0;i<=max;i++)
        count[i] = 0;
    //CountSorting...
    for (int i = l; i <= h; i++)
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

float median(int a[], long int start, long int stop)
{
    long int mid = start+((stop-start)/2);
    float avg = (((float)a[mid])+((float)a[mid+1]))/2;
    //printf("%.2f %.2f",avg,(float)a[mid]);
    if((stop-start+1)%2!=0)
        return ((float)a[mid]);
    else
        return avg;
    
}
int main()
{
    long int n,d,notification=0;
    scanf("%ld %ld",&n,&d);
    int a[n],copy[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        copy[i] = a[i];
    }
    for(int i=d;i<n;i++)
    {
        countSort(a, i-d, i-1);
        if(copy[i]>=(2*median(a,i-d,i-1)))
            notification++;
        for(int j=i-d;j<=i-1;i++)
            a[j] = copy[j];
    }
    printf("%ld",notification);
}











