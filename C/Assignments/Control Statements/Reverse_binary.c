// WRITE A PROG TO REVERSE BITS OF GIVEN INT NUMBER.

#include <stdio.h>
void binary(int, int);
int main()
{
    int num, i, j;
    int pos = sizeof(num) * 8 - 1;

    printf("Enter the number : ");
    scanf("%d", &num);
    printf("\n");

    printf("The Given number Binary is\n");
    binary(num, pos);

    for (i = 0, j = pos; i <= j; i++, j--)
    {
        if ((num >> i & 1) != (num >> j & 1))
        {
            num ^= (1 << i);
            num ^= (1 << j);
        }
    }

    printf("The after reverse number Binary is\n");
    binary(num, pos);

    printf("After revers Number is = %d\n\n", num);

    /*
    printf("The revers number Binary is\n");
    for(i=0;pos>=0;i++)
    {
        pos--;
        printf("%d",num>>i&1);
    }
    printf("\n");
    */
}

void binary(int num, int pos)
{
    for (pos; pos >= 0; pos--)
        printf("%d", (num >> pos) & 1);
    printf("\n\n");
}