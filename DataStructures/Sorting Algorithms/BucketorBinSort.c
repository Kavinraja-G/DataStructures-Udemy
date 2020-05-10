#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void insert(struct node **t, int data)
{
    struct node *p;
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if(*t == NULL)
    {
        (*t) = n;
    }
    else
    {
        p = (*t);
        while(p->next != NULL)
            p=p->next;
        p->next = n;
    }
}

int delete(struct node **t)
{
    struct node *p;
    p = (*t);
    int x = (*t)->data;
    (*t) = (*t)->next;
    free(p);
    return x;
}

void binSort(int a[], int n)
{
    int i=0,j=0;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    //Creating a array of linkedList:
    struct node **bins;
    bins = (struct node **)malloc((max+1)*sizeof(struct node *));
    for(int i=0;i<=max;i++)
        bins[i] = NULL;
    for(int i=0;i<n;i++)
        insert(&bins[a[i]],a[i]);
    while(i<max+1)
    {
        while (bins[i]!=NULL)
            a[j++] = delete(&bins[i]);
        i++;
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
    binSort(a,size);
    printf("\nAfter sorting the elements: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");    
}