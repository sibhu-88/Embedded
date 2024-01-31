//WAPT find the string in revers formet

#include<stdio.h>

int main()
{
    char s[10];
    int i;

    printf("Enter the string : ");
    scanf("%s",s);

    int n=sizeof s;

    for ( i = n-1; i>=0; i--)
    printf("%c",s[i]);    
    
    printf("\n");
}

