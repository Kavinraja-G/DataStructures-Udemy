#include<stdio.h>
#include<string.h>
//PROGRAM TO GENERATE THE PERMUTATION OF STRINGS USING STATE SPACE TREE AND BACKTRACKING
void permutation(char s[], int k)
{
    static int a[10] = {0};
    static char r[10];

    if(s[k] == '\0')
    {
        printf("%s\n",r);
    }
    else
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(a[i]==0)
            {
                r[k] = s[i];
                a[i] = 1;
                permutation(s,k+1);
                a[i] = 0;
            }
        }
    }
}
int main()
{
    char s[] = "ABC";
    permutation(s, 0);
}