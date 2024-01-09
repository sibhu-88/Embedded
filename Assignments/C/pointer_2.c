#include<stdio.h>

int main()
{
    double x=22.7;
    
    printf("Binary of int pointer \n");
    char *p=(char *)&x;
    int pos = sizeof(*p) * 8 - 1;
    for (pos; pos >= 0; pos--)
        printf("%d", (*p >> pos) & 1);
    printf("\n\n");

}