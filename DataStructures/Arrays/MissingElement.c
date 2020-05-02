//Program to find the missing element in the contigous array

#include<stdio.h>
int main()
{
    int a[] = {5,6,7,8,11,12,13};
    int low = a[0];
    int length = 7;
    int diff = low - 0;

/*     for(int i=0;i<length;i++)
    {
        if(a[i]-i != diff)
        {    
            printf("Element missing is %d",i+diff);
            break;
        }
    } */

    for(int i=0;i<length;i++)
    {
        if(a[i]-i != diff)
        {
            while(diff< a[i]-i) //Here we are increasing the difference so that it prints all the missing elements
            {
                printf("Element missing is %d\n",i+diff);
                diff++;
            }
        }
    }

}