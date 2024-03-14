// Write a program to find the no.of prime numbers from the given array elements and display it.

#include <stdio.h>
int main()
{
    int i, j, a[10], count = 0;

    int ele = sizeof a / sizeof a[0];

    printf("Enter the array values : ");
    for (i = 0; i < ele; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < ele; i++)
    {
        for (j = 2; j < a[i]; j++)
        {
            if ((a[i] % j) == 0)
                break;
        }
        if (j == a[i])
            count++;
    }

    printf("The no.of prime numbers from the given array elements = %d", count);
}