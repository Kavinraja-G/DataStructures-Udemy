/* After getting her PhD, Christie has become a celebrity at her university, and her facebook profile is full of friend requests. Being the nice girl she is, Christie has accepted all the requests.

Now Kuldeep is jealous of all the attention she is getting from other guys, so he asks her to delete some of the guys from her friend list.

To avoid a 'scene', Christie decides to remove some friends from her friend list, since she knows the popularity of each of the friend she has, she uses the following algorithm to delete a friend.

Algorithm Delete(Friend):
    DeleteFriend=false
    for i = 1 to Friend.length-1
         if (Friend[i].popularity < Friend[i+1].popularity)
            delete i th friend
            DeleteFriend=true
            break
    if(DeleteFriend == false)
        delete the last friend

Input:
First line contains T number of test cases. First line of each test case contains N, the number of friends Christie currently has and K ,the number of friends Christie decides to delete. Next lines contains popularity of her friends separated by space.

Output:
For each test case print N-K numbers which represent popularity of Christie friends after deleting K friends.

Constraints
1<=T<=1000
1<=N<=100000
0<=K< N
0<=popularity_of_friend<=100

NOTE:
OrdeLE OUTPUT 
100 1 
19 12 17 
77 18 LE OUTPUT 
100 1 
19 12 17 
77 18 
23 45 11 77 18
SAMPLE OUTPUT 
100 1 
19 12 17 
77 18  */


#include<stdio.h>
#include<malloc.h>

struct node
{
    int popularity;
    struct node *next;
}*head=NULL;

void insert(struct node *t, int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->popularity = data;
    new->next = NULL;
    if(head == NULL)
    {
        head = new;
        head->next = NULL;
    }
    else
    {
        t = head;
        while (t->next!=NULL)
            t = t->next;
        t->next = new;
        t = new;
    }
}

void display(struct node *t)
{
    t = head;
    while (t->next!=NULL)
    {
        printf("%d ",t->popularity);
        t =t->next;    
    }
    printf("%d ",t->popularity);
}


void delete(struct node *t)
{
    struct node *temp,*join;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next= NULL;
    t = head;
    int flag = 0;
    if(head->popularity < head->next->popularity)
    {
        head = head->next;
        return;
    }
    while (t->next->next!=NULL)
    {
        temp = t;
        t = t->next;
        if(t->popularity < t->next->popularity)
        {

            flag = 1;
            temp->next = t->next;
            t = t->next;
            break;
        }
    }
    if(flag == 0)
        t->next = NULL;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        head = NULL;
        int n,k;
        scanf("%d %d",&n,&k);
        for(int j=0;j<n;j++)
        {
            int data;
            scanf("%d",&data);
            insert(head,data);
        }
        while (k!=0)
        {
            delete(head);
            k--;
        }
        display(head);
        free(head);
        printf("\n"); 
    }   
}