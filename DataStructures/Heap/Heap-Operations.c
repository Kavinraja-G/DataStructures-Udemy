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

void delete(int a[], int n)
{
    int i=1,j = 2*i;
    int x = a[1];
    a[1] = a[n]; //Replace the last most node in the root of the heap
    while (j < n-1)
    {
        if(a[j+1] > a[j])
            j = j+1;
        if(a[i]<a[j])
        {
            //swap a[i] and a[j]
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i = j;
            j = 2*i; 
        }
        else  //Indicates that the position is in the right place of the heap
            break;
    }
    a[n] = x; //Here the root data is copied to empty removed end before
}

int main()
{
    int a[] = {0,40,35,30,15,10,25,5};
    for(int i=2;i<8;i++)
    {
        insert(a,i); //Inserting the array elements in the max_heap order
    }

    printf("Heap Elements after Insertion: ");
    for(int i=0;i<8;i++)
        printf("%d ",a[i]);

    for(int i=7;i>0;i--)
        delete(a,i);

    //Thus by deleting all the elements of the max-heap after insertion we get the array of sorted elements 
    printf("\nHeap Elements after Deletion: ");
    for(int i=0;i<8;i++)
        printf("%d ",a[i]);

}