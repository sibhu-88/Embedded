//WAPT find the string lenth

#include<stdio.h>

int main()
{
    char name[100];
    int i,count=0;

    printf("Enter the string : ");
    scanf("%s",name);

    for ( i = 0; name[i]; i++)
    count++;
    

    printf("no.of strings : %d\n",count);
}