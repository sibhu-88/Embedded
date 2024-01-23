//wap to revers the given string.

#include<stdio.h>

void reverse(char *);
int main() {
    char s[20];

    printf("Enter the string : ");
    scanf("%s",s);

    reverse(s);
    
}

void reverse(char *s)
{
    int i,j,k,temp;

    for ( k = 0; s[k]; k++);

    for ( i = 0,j=k-1; i < j; i++,j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    printf("%s",s);
    printf("\n");
}