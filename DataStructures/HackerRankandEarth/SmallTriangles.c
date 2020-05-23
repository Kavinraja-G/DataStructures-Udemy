#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float calcArea(triangle *tr)
{
    float p = (tr->b +tr->c+ tr->a)/(2.0);
    float s = (p*(p - tr->a)*(p - tr->b)*(p - tr->c));
    return s;
}

void swap(triangle* tr, int i,int j)
{
    int temp = tr[i].a;
    tr[i].a = tr[j].a;
    tr[j].a = temp;
    temp = tr[i].b;
    tr[i].b = tr[j].b;
    tr[j].b = temp;        
    temp = tr[i].c;
    tr[i].c = tr[j].c;
    tr[j].c = temp;
}

void sort_by_area(triangle* tr, int n) {

    for (int i = 1; i < n+1; i++)
    {
        //printf("%f \n",calcArea(&tr[i]));
        float key = calcArea(&tr[i]);
        int j = i-1;
        while ((j>=0) && (calcArea(&tr[j])>key))
        {
            swap(tr,j+1,j);
            j--;
        }
        swap(tr,i,j+1);
    }
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}