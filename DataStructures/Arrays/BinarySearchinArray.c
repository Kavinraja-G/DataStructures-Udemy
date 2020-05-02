#include<stdio.h>
#include<math.h>
struct Array
{
    int A[20];
    int size;
    int length;
};

//Since the recursion for this algorithm will be tail recursion hence it is better to use Loop

int binarySearch(struct Array arr,int low,int high,int key)
{
    int mid = 0;
    while(low<=high)
    {
        mid = floor((low+high)/2);
        if(arr.A[mid] == key)
            return mid;
        else if(key < arr.A[mid])
        {
            high = mid-1; //For recursion use: binarySearch(arr,low,mid-1,key);
        }
        else
        {
            low = mid+1;  //For recursion use: binarySearch(arr,mid+1,high,key);
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2,4,6,8,10,12,14,16,18,20},20,10};
    int key = 2;
    int low = 0,high = arr.length,mid=0;
    int value = binarySearch(arr,low,high,key);
    printf("Found at index: %d",value);
}