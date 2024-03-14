// WAPT CHECK THE GIVEN NUM IS PRIME NUM OR NOT

#include <stdio.h>
int prime_num(int);
int main()
{
    int num;

    printf("Enter the number : ");
    scanf("%d", &num);

    prime_num(num);
}

int prime_num(int x)
{
    int i;
    if (x == 2)
    {
        printf("The Given Number %d Is Prime Number\n", x);
    }
    else if (x == 1)
    {
        printf("The Given Number %d Is Not A Prime NUmber\n", x);
        return 0;
    }

    for (i = 2; i < x; i++)
    {
        if ((x % i) != 0)
        {
            if (i == (x - 1))
            {
                printf("The Given Number %d Is Prime Number\n", x);
            }
        }
        else
        {
            printf("The Given Number %d Is Not A Prime NUmber\n", x);
            break;
        }
    }
}