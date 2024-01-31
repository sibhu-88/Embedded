#include<stdio.h>
#include<math.h>

void checkArmstrong(int);

int main() {
    int num;

    printf("Enter the Number : ");
    scanf("%d", &num);

    checkArmstrong(num);

    return 0;
}

void checkArmstrong(int x) {
    int originalNum = x;
    int count = 0, add = 0, digit;

    while (x > 0) {
        x /= 10;
        count++;
    }

    x = originalNum;

    while (x > 0) {
        digit = x % 10;
        add += pow(digit, count);
        x /= 10;
    }

    if (originalNum == add) {
        printf("The Given Number %d is an Armstrong number\n", originalNum);
    } else {
        printf("The Given Number %d is not an Armstrong number\n", originalNum);
    }
}
