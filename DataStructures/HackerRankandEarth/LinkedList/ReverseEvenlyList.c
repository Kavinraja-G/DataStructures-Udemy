 #include<stdio.h>
 #include<malloc.h>
 #include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL;

void insert(struct node *t, int data)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
	new->next = NULL;
	if(head==NULL)
	{
        t = new;
        head = t;
        head->next = NULL;
	}
    else
    {
	    t = head;
        while (t->next!=NULL)
        {
            t = t->next;
        }
        t->next = new;
        t = new; t->next = NULL;
    }
}
			//free(curr); free(prev); free(after);

void display(struct node *t)
{
  t = head;
  while (t->next!=NULL)
  {
      printf("%d->",t->data);
      t = t->next;
  }
  printf("%d ",t->data);    
}

void reverseEven(struct node *t)
{
    struct node *start=NULL,*end=NULL,*join=NULL;
    t = head;
    start = head;
    join = head;
    while(t!=NULL && t->next!=NULL)
    {
        if(t->data %2==0 && t->next->data%2 == 0)
        {
            struct node *originalEnd=NULL;
            start = t;
            while (t->next!=NULL && t->data %2==0)
            {
                end = t;
                originalEnd = t;
                t = t->next;
            }
            //For tail case:
            if(t->data%2==0 && t->next==NULL)
            {
                end = t;
                originalEnd = t;
            }
            //For head case:
            if(join == start && join==head)
            {
                join = originalEnd;
                head = originalEnd;
            }
            join->next = originalEnd;
            struct node *prev = NULL,*curr = NULL,*after = NULL;
            prev = start;curr = prev->next; if(t->next!=NULL) prev->next = t; else prev->next = NULL;
            while (curr!=NULL && curr!=originalEnd)
            {
                if(curr->next!= NULL )after = curr->next;
                else after = NULL;
                curr->next = prev;
                prev = curr;
                curr = after;
            }
            originalEnd->next = prev;
            end = t; join = t; t = t->next;
        }
        else
        {
            end = t;
            join = t;
            t = t->next;
        }
    }
}


 int main()
 {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        insert(head,data);
    }
    printf("\n");
    reverseEven(head);
    display(head);
 }