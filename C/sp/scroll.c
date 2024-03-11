#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void scroll(int);
int main()
{
    int i;
    while (1)
    {
        for ( i = 0; i < 104; i++)
            scroll(i);
        for ( i--; 0 <= i; i--)
            scroll(i);
        
    } 
}

void scroll(int i)
{
    int j;
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n");

    for ( j = 0; j < i; j++)
        printf(" ");

    puts("SIVA PRABHU");
    printf("\n\n\n\n\n\n\n\n");
    usleep(80000);
}