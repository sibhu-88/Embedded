//WRITE A PROG TO FINND FACTORIAL OF A GIVEN NUMBER.

#include<stdio.h>

int main()
{
    int n,i=1,factorial = 1;

    printf("Enter the number need factorial : ");
    scanf("%d",&n);

    // while (i<=n)
    // {
    //     factorial *= i;
    //     i++;
    // }
    
    for (i; i <= n; i++) {
        factorial *= i;
    }

    printf("The factorial of %d is = %d\n", n, factorial);
    return 0;
}