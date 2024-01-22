//wapt count num even and odd digits the given int num.

#include<stdio.h>

void countEvenOdd(int);

int main() {
    int x;

    printf("Enter the X value : ");
    scanf("%d", &x);

    countEvenOdd(x);

    return 0;
}

void countEvenOdd(int x) {
    int evenCount = 0, oddCount = 0, num;

    while (x != 0) {
        num = x % 10;
        if (num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
        x /= 10;
    }

    printf("Even numbers are = %d\nOdd numbers are = %d\n", evenCount, oddCount);
}
