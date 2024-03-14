// check the given number is perfect number or not.

#include <stdio.h>

void checkPerfect(int);

int main()
{
    int num;

    printf("Enter the Number : ");
    scanf("%d", &num);

    checkPerfect(num);

    return 0;
}

void checkPerfect(int x)
{
    int sum = 0;

    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
        {
            sum += i;
        }
    }

    if (sum == x)
    {
        printf("The Given Number %d is a Perfect Number\n", x);
    }
    else
    {
        printf("The Given Number %d is Not a Perfect Number\n", x);
    }
}
