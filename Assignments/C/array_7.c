//Write a program that how many number of times each array element is present in a given array.

#include<stdio.h>
int main()
{
    int i,j,k,l,a[5],count;

    int ele = sizeof a/sizeof a[0];

    printf("Enter the array values : ");
    for ( i = 0; i < ele; i++) 
    scanf("%d",&a[i]);

    for ( i = 0; i < ele; i++)
    {
        
            for ( k = 0,count=0; k < ele; k++)
            {
                if (a[i]==a[k])
                count++;
            }
            
            printf("%d is present ===> %d\n",a[i],count);
    }
}

