#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define PC "\033[0;3%dm"

int main()
{
    int j;
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n");

    for ( j = 0; j < 8; j++)
    {
        printf(PC"SIVA PRABHU",j);
        sleep(1);
    }

    printf("\n\n\n\n\n\n\n\n");
}