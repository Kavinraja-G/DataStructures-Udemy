
#include<stdio.h>
int main()
{
    int a[] = {5,6,7,8,10,11,12};
    int min = a[0];
    int max = 7;
    int length = 7;
    for(int i=0;i<length;i++)
    {
        if(a[i]<min)
            min = a[i];
        else if(a[i]>max)
            max = a[i];
    }
    printf("Max: %d\nMin: %d",max,min);

}