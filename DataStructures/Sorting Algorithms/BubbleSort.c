#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int a[], int n)
{
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                flag=1;
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
        if(flag==0)
        {
            printf("Already Sorted.\n");
            break;
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
    bubbleSort(a,size);
    printf("After sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
}