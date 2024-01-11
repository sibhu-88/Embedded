//Write a program to find the no.of even and odd numbers From the given array elements.
#include<stdio.h>
int main()
{
    int i,j,a[10],count1=0,count2=0;

    int ele = sizeof a/sizeof a[0];

    printf("Enter the array values : ");
    for ( i = 0; i < ele; i++) 
    scanf("%d",&a[i]);

    for ( i = 0; i < ele; i++)
    {
        if ((a[i]%2)==0)
        count1++;
        else
        count2++;
    }

    printf("The no.of odd numbers From the given array elements = %d\n",count1);
    printf("The no.of even numbers From the given array elements = %d\n",count2);
    
}