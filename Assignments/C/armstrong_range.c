#include<stdio.h>
#include<math.h>

int checkArmstrong(int);

int main() {
    int num=1, num1=200,sum,i;

    for ( i = num; i <= num1; i++)
    {
        sum = checkArmstrong(i);

        if (sum==i)
        printf("%d, ",sum);   
    }
    return 0;
}

int checkArmstrong(int x) {
    int count = 0, add = 0, digit,i;

    for ( i = x; i!=0; i/=10)
    count++;
    
    for ( i = x; i!=0; i/=10)
    {
    digit = i % 10;
    add += pow(digit, count);
    }
    return add;
}
