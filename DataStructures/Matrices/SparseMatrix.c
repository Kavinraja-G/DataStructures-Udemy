#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct element {
    int i;
    int j;
    int x;
};

struct SparseMatrix
{
    int r;
    int c;
    int x;
    struct element *e;
};

void createMatrix(struct SparseMatrix *s)
{
    printf("Enter the dimensions: ");
    scanf("%d %d",&s->r,&s->c);
    printf("\nEnter the no.of Non-zero elements: ");
    scanf("%d",&s->x);
    s->e = (struct element *)malloc(s->x * sizeof(struct element));
    printf("\nEnter the non-zero elements: \n");
    for(int i=0;i<s->x;i++)
        scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
}

void display(struct SparseMatrix s)
{
    int k=0; //To keep track the sparse array index
    for(int i=0;i<s.r;i++)
    {
        for(int j=0;j<s.c;j++)
        {
            if((i == s.e[k].i) && (j== s.e[k].j))
                printf("%d ",s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct SparseMatrix * sum(struct SparseMatrix s1,struct SparseMatrix s2)
{
    struct SparseMatrix *sum;
    int i=0,j=0,k=0;
    if((s1.r != s2.r) || (s1.c != s2.c))
    {
        printf("Addition not possible\n");
        exit(0);
    }
    else
    { 
        sum = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
        sum->x = s1.x + s2.x;
        sum->e = (struct element *)malloc(sum->x * sizeof(struct element));
        
        while(i< s1.x && j<s2.x)
        {
        if(s1.e[i].i < s2.e[j].i)
            sum->e[k++] = s1.e[i++];
        else if(s1.e[i].i > s2.e[j].i)
            sum->e[k++] = s2.e[j++];
        else
            {
            if(s1.e[i].j < s2.e[j].j)
            sum->e[k++] = s1.e[i++];
            else if(s1.e[i].j > s2.e[j].j)
            sum->e[k++] = s2.e[j++];
                else
                {
                sum->e[k] = s1.e[i++]; //First keep any one element inside and then add
                sum->e[k++].x += s2.e[j++].x; //Now add the other element
                }
            }
        }
    }
    for(;i<s1.x;i++) sum->e[k++] = s1.e[i];
    for(;j<s2.x;j++) sum->e[k++] = s2.e[j];
    sum->r = s1.r; sum->c = s1.c; 
    sum->x = k;

    return sum;
}


int main()
{
    struct SparseMatrix s1,s2,*s3;
    printf("--------------------\n");
    createMatrix(&s1);
    printf("MATRIX 1--------------\n");
    display(s1);
    printf("\n--------------------\n");
    createMatrix(&s2);
    printf("MATRIX 2--------------\n");
    display(s2);
    s3 = sum(s1,s2);
    printf("SUM-------------------\n");
    display(*s3);
}