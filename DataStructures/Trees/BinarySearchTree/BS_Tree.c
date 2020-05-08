#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

struct node * insert(struct node *r, int key)
{
    struct node *t;
    if(r==NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->left = NULL; t->right = NULL;
        return t;
    }
    if(key < r->data)
    {
        r->left = insert(r->left , key);
    }
    else if(key>r->data)
    {
        r->right = insert(r->right, key);
    }
    return r;
}

void inOrder(struct node *t)
{
    if(t)
    {
        inOrder(t->left);
        printf("%d ",t->data);
        inOrder(t->right);
    }
}

int main()
{
    root = insert(root,20);
    insert(root,10);
    insert(root,50);
    inOrder(root);

}
/*     int op=1;
    while (op)
    {
        int c;
        printf("Enter the operation to perform in BS-Tree:\n1. To insert\n2. To delete\n3. To display\n0.To Exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
        {    
            int data;
            printf("Enter the data to insert: \n");
            scanf("%d",&data);
            root = insert(root,data);            
            break;
        }
        case 3:
            inOrder(root);
        case 0:
            op=0;
            break;
        default:
            break;
        }
    }   */ 