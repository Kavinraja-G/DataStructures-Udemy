#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct terms
{
    int c; //Coefficient
    int e; //Exponents
};

struct polynomial
{
    int n;
    struct terms *t;
};

void create(struct polynomial *p)
{
    printf("Enter the no.of terms: ");
    scanf("%d",&p->n);
    p->t = (struct terms *)malloc(p->n * sizeof(struct terms));
    printf("\nEnter the polynomial terms: ");
    for(int i=0;i<p->n;i++)
    {
        printf("\nValues of terms %d: ",i);
        scanf("%d %d",&p->t[i].c,&p->t[i].e);
    }
}

struct polynomial * add(struct polynomial p1, struct polynomial p2)
{
    int i=0,j=0,k=0;
    struct polynomial *sum;
    sum = (struct polynomial *)malloc(sizeof(struct polynomial));
    (p1.n>=p2.n) ? (sum->n = p1.n) : (sum->n = p2.n);
    sum->t = (struct terms *)malloc(sum->n * sizeof(struct terms));
    while(i<p1.n && j<p2.n)
    {
        if(p1.t[i].e > p2.t[j].e)
            sum->t[k++] = p1.t[i++];
        else if(p1.t[i].e < p2.t[j].e)
            sum->t[k++] = p2.t[j++];
        else
        {
            sum->t[k].e = p1.t[i].e;
            sum->t[k].c = p1.t[i].c + p2.t[j].c;
            k++;i++;j++;
        }
    }
    for(;i<p1.n;i++)
        sum->t[k++] = p1.t[i];
    for(;j<p1.n;j++)
        sum->t[k++] = p1.t[j];

    return sum;
}

void display(struct polynomial p)
{
    for(int i=0;i<p.n;i++)
        printf("%dx^%d_",p.t[i].c,p.t[i].e);
    printf("\n");
}

int main()
{
    struct polynomial p1,p2,*sum;
    printf("Enter the polynomial 1: \n"); create(&p1);
    printf("Enter the polynomial 2: \n"); create(&p2);
    
    printf("\nPolynomial 1 =>");  
    display(p1);
    printf("\nPolynomial 2 =>");  
    display(p2);
    
    sum = add(p1,p2);
    printf("\nSum of the polynomials =>");  display(*sum);
    
}
