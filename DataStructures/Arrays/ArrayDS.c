#include<stdio.h>
#include<malloc.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Append(struct Array *arr,int value) //*arr is used because we are modifying the array 
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++] = value;
    }
}

void insert(struct Array *arr,int index,int value)
{
    if(arr->length >=index && index>=0)
    {
        for(int i = arr->length;i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = value;
        arr->length++;
    }

}

void delete(struct Array *arr,int index)
{
    if(index<= arr->length)
    {
        for(int i = index;i<arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    }

}

void didplay(struct Array arr)
{
    printf("\nDisplaying the Array: ");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int linearSearch(struct Array arr, int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(key == arr.A[i])
            return i;
    }
    return -1;
}
int main()
{
    struct Array arr={{2,4,6,8,10},20,5};
    printf("\nInitial State of an array...");
    didplay(arr);
    printf("\nAppending...");
    Append(&arr,100);
    didplay(arr);
    printf("\nInserting...");
    insert(&arr,2,50);
    didplay(arr);
    printf("\nDeleting...");
    delete(&arr,10);
    didplay(arr);
    printf("\nLinear Search...");
    int key = 6;
    printf("\nElement %d is at index: %d",key,linearSearch(arr,key));
}