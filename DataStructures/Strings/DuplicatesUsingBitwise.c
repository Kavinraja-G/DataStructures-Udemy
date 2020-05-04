#include<stdio.h>
#include<string.h>
int main()
{
    char A[] = "finding";
    long int H = 0, X = 0;
    for(int i=0;i<strlen(A);i++)
    {
        X = 1;
        X = X<<(A[i]-97); //Shifting towards the required positon in the bitset
        if((X&H) >0) //Here we mask and check whether the bit is set or not at the found position
            printf("%c is duplicate\n",A[i]);
        else
            H = X | H; //If it is not set that is it is a new char then merge it (Set to 1)
        
    }
}