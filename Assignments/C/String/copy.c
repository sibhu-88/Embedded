//wap to revers the given string.

#include<stdio.h>

void copy(char *,char *);
int main() {
    char s[20],b[20];

    printf("Enter the string : ");
    scanf("%s",s);

    copy(s,b);
    
}

void copy(char *b,char *s)
{
    int i;

    for ( i = 0; s[i] ; i++)
    b[i] = s[i];
    
    printf("After copy : %s",b);
    printf("\n");
}