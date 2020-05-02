#include<stdio.h>
#include<malloc.h>

int main()
{
    int *p,*q;
    p = (int*)malloc(5 *sizeof(int));
    for(int i=0;i<5;i++)
        p[i] = (i+10);
    q = (int*)malloc(10 *sizeof(int));

    for(int i=0;i<5;i++)
        q[i] = p[i];
    free(p); //Free the memory due to memory leak possibility.
    p=q; //Changing the pointer to point q
    q = NULL; //Making q as NULL
    for(int i=0;i<10;i++)
        printf("%d ",p[i]);
}