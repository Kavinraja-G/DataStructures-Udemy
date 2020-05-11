#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define SIZE 10;

int hash(int key)
{
    return key%10;
}
//Quadratic Probing we use f(i) = i*i
int probe(int HT[], int key)
{
    int i=0;
    int index = hash(key);
    while(HT[(index+(i*i))%10]!=0)
        i++;
    return (index+(i*i))%SIZE;
}

void insert(int HT[], int key)
{
    int index = hash(key);
    if(HT[index]!=0)
        index = probe(HT,key);
    HT[index] = key;
}

int search(int HT[], int key)
{
    int index = hash(key);
    int i=0;
    while(HT[(index+(i*i))%10]!=key)
    {
        i++;
        if(HT[(index+(i*i))%10]==0)
            return -1;
    }
    return (index+(i*i))%SIZE;
}

int main()
{
    int HT[10]={0};
    insert(HT,12);
    insert(HT,15);
    insert(HT,25);
    insert(HT,23);
    printf("HashTable Created: \n");
    for(int i=0;i<10;i++)
        printf("%d ",HT[i]);
    printf("\nKey found at Index %d in the HashTable\n",search(HT,23));

}