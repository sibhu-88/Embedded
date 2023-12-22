//Wap to impliment a user implement power function.

#include<stdio.h>

int power(int base, int exponent) {
    if (exponent == 0) 
    {
        int result = 1;
        while (exponent > 0) 
        {
            result *= base;
            exponent--;
        }
    }
    return result;
}

int main() {
    int base, exponent, result;

    printf("Enter the base and exponent: ");
    scanf("%d %d", &base, &exponent);

    result = power(base, exponent);

    printf("%d raised to the power of %d is = %d\n", base, exponent, result);

    return 0;
}
