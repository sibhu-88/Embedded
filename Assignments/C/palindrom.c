//wap to check the given int num is palindrom num or not.

#include<stdio.h>

void checkPalindrome(int);

int main() {
    int x;

    printf("Enter the X value : ");
    scanf("%d", &x);

    checkPalindrome(x);

    return 0;
}

void checkPalindrome(int n) {
    int reverseNum = 0, originalNum = n;

    while (n != 0) {
        int digit = n % 10;
        reverseNum = reverseNum * 10 + digit;
        n /= 10;
    }

    if (originalNum == reverseNum) {
        printf("Yes, It is a palindrome number\n");
    } else {
        printf("No, It is not a palindrome number\n");
    }
}