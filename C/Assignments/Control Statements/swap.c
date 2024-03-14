// WRITE A PROG TO SWAP TWO INT NUMBER USING BITWISE OPERATOR USE ONLY '^' OPERATION.

#include <stdio.h>

void binary(int);

int main()
{
    int x, y;
    int pos = sizeof(x) * 8 - 1;

    printf("Enter the X & Y values: \n");
    scanf("%d%d", &x, &y);

    printf("Before swapping, x = %d\n", x);
    binary(x);

    printf("Before swapping, y = %d\n", y);
    binary(y);

    for (int i = 0; i <= pos; i++)
    {
        if ((x >> i & 1) != (y >> i & 1))
        {
            x ^= (1 << i);
            y ^= (1 << i);
        }
    }

    printf("After swapping, x = %d\n", x);
    binary(x);

    printf("After swapping, y = %d\n", y);
    binary(y);
}

void binary(int num)
{
    int pos = sizeof(num) * 8 - 1;
    for (pos; pos >= 0; pos--)
        printf("%d", (num >> pos) & 1);
    printf("\n\n");
}
