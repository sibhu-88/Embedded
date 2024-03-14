// Write a program that how many number of times each array element is present in a given array.

#include <stdio.h>
int main()
{
    int i, j, a[5], count;

    int n = sizeof a / sizeof a[0];

    printf("Enter the array values : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
    {
        count = 1;
        for (j = 0; j < i; j++)
        {
            if (a[i] == a[j])
                break;
        }

        if (j == i)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                    count++;
            }
            printf("%d is present ===> %d\n", a[i], count);
        }
    }
    return 0;
}
