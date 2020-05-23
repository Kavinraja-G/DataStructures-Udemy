 #include<stdio.h>
 #include<malloc.h>
 #include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL;

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->s = (int *)malloc(size * sizeof(int));
}

void push(struct Stack *st, int data)
{
    if(st->top == st->size-1)
        printf("Stack is Full and Overflow.\n");
    else
    {
        st->top++;
        st->s[st->top] = data;
    }
}

int pop(struct Stack *st)
{
    int data = -1;
    if(st->top == -1)
        printf("Stack is Empty.\n");
    else
    {
        data = st->s[st->top];
        st->top--;
    }
    return data;
}


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

void display(struct node *t)
{
  t = head;
  while (t->next!=NULL)
  {
      printf("%d ",t->data);
      t = t->next;
  }
  printf("%d ",t->data);    
}

void reverseEven(struct node *t)
{
    struct node *start=NULL,*end=NULL;
    struct Stack *s;
    s = malloc(sizeof(struct Stack));
    create(s,1000);
    t = head;
    end = head;
    while(t!=NULL && t->next!= NULL)
    {
        if(t->data%2 != 0)
            t = t->next;

        else if(t->data%2 == 0 && t->next->data%2==0)
        {
            start = t;
            while(t!=NULL && t->data%2==0)
            {
                end = t;
                if(t->next==NULL) break; 
                t = t->next;
            }
            struct node *temp=NULL;
            temp = start;
            while(temp != end)
            {
                push(s,temp->data);
                temp = temp->next;
            }
            push(s,temp->data);
            //displayStack(s);
            struct node *in=NULL;
            in = start;
            while(in != end)
            {
                in->data = pop(s);
                in = in->next;
            }
            in->data = pop(s);
            t = t->next;
        }
        else
            t = t->next;
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