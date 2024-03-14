// Write a program to copy one array elements into another array.

#include <stdio.h>
int main()
{
    int i, a[10], b[10];

    int ele = sizeof a / sizeof a[0];

    printf("Enter the array values : ");
    for (i = 0; i < ele; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < ele; i++)
    {
        b[i] = a[i];
    }

    for (i = 0; i < ele; i++)
    {
        printf("a[%d]=%d b[%d]=%d \n", i, a[i], i, b[i]);
    }
}