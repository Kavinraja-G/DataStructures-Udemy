#include<stdio.h>
// Our target of the problem is to move the disk from A to C using B
int TOH(int n,int A,int B,int C)
{
    if(n>0)
    {
        //Mostly it performs the inorder traversal of a tree.
        TOH(n-1,A,C,B); //From A to B using C at the ascending time
        printf("Tower:%d to Tower:%d\n",A,C);
        TOH(n-1,B,A,C); //From B to C using A at the descending time
    }
}

int main()
{
    int n=3,A=1,B=2,C=3;
    TOH(n,A,B,C);
}
