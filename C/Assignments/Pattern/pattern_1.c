#include <stdio.h>
int main()
{
    int i, j, k, n, x, y;

    printf("Enter the number ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        x = 1, y = 2;
        for (j = 0; j < i + 1; j++)
            if (i % 2 != 0)
            {
                printf("%d ", j + (y++));
            }
            else
            {
                printf("%d ", j + (x++));
            }

        printf("\n");
    }
}