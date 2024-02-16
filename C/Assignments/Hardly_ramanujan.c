#include<stdio.h>

int Hardly_ramanujan(int);

int main() {
    int n1 = 1, n2 = 100000, i;

    for (i = n1; i <= n2; i++) {
        int rst = Hardly_ramanujan(i);

        if (i == rst)
            printf("%d, ", i);
    }
    printf("\n");

    return 0;
}

int Hardly_ramanujan(int x) {
    int sum = 0, rst = 0, i;

    // Calculate sum of digits
    for (i = x; i > 0; i /= 10)
        sum += (i % 10);

    // Reverse the sum of digits
    for (i = sum; i > 0; i /= 10)
        rst = (rst * 10) + (i % 10);

    sum *= rst;

    return sum;
}
