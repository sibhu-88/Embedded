// check the given number is strong num or not

#include <stdio.h>

int main()
{
    int num, n, i, factorial, rem, total = 0;

    printf("Enter the number need factorial : ");
    scanf("%d", &num);

    n = num;
    while (n != 0)
    {
        rem = n % 10;
        n /= 10;
        factorial = 1;
        for (i = 1; i <= rem; i++)
        {
            factorial *= i;
        }
        total += factorial;
    }

    if (num == total)
    {
        printf("Given number is strong number");
    }
    else
    {
        printf("Given number is not a Strong number");
    }

    return 0;
}