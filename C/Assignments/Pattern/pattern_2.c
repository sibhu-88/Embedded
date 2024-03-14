#include <stdio.h>
int main()
{
    int i, j, k, n;
    char ch;

    printf("Enter the number ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        ch = 'A';
        for (j = 0; j <= i; j++)
            printf("  ");

        for (k = 1; k <= n - i; k++)
            if (i % 2 != 0)
            {
                printf("%d ", k);
            }
            else
            {
                printf("%c ", ch++);
            }

        printf("\n");
    }
}