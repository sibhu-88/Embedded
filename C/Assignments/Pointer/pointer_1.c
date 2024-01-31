#include<stdio.h>

int main()
{
    float x=22.7;
    
    
    printf("Binary of int pointer \n");
    int *p=(int *)&x;
    int pos2 = sizeof(*p) * 8 - 1;
    for (pos2; pos2 >= 0; pos2--)
        printf("%d", (*p >> pos2) & 1);
    printf("\n\n");
    
    
    printf("Binary of short int pointer \n");
    short int *a=(short int *)&x;
    int pos3 = sizeof(*a) * 8 - 1;
    for (pos3; pos3 >= 0; pos3--)
        printf("%d", (*a >> pos3) & 1);
    printf("\n\n");
    
    
    printf("Binary of char pointer \n");
    char *b=(char *)&x;
    int pos4 = sizeof(*b) * 8 - 1;
    for (pos4; pos4 >= 0; pos4--)
        printf("%d", (*b >> pos4) & 1);
    printf("\n\n");
}
