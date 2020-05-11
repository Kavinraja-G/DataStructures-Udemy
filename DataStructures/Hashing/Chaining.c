#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node *next;
};
void SortedInsert(struct Node **H,int x)
{
    struct Node *t,*q=NULL,*p=*H;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(*H==NULL)
        *H=t;
    else
    {
    while(p && p->data<x)
    {
        q=p;
        p=p->next;
    }
    if(p==*H)
    {  
        t->next=*H;
        *H=t;
    }
    else
    {
        t->next=q->next;
        q->next=t;
    }
    }

}
struct Node *Search(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
//Return the hash table index
int hash(int key)
{
    return key%10;
}

void insert(struct Node *h[], int key)
{
    int i = hash(key);
    SortedInsert(&h[i],key);
}

int main()
{
    struct Node *HashTable[10];
    struct Node *t;
    for(int i=0;i<10;i++)
        HashTable[i] = NULL;
    
    insert(HashTable, 2);
    insert(HashTable, 22);
    insert(HashTable, 32);

    t = Search(HashTable[hash(2)], 2);
    printf("%d ",t->data);
}