//WAPT strncpy function

#include<stdio.h>

void str_ncpy(char *,char *,int);
int main() {
    char s[50],b[50];
    int n;

    printf("Enter the string : ");
    scanf("%[^\n]",s);

    printf("Enter the numer of string want copy : ");
    scanf("%d",&n);

    str_ncpy(b,s,n);
}

void str_ncpy(char *b,char *s,int n)
{
    int i,j;

    for ( i = 0; s[i] ; i++);

    for ( j = 0; j < n ; j++)
    {
        b[j] = s[j];
    }
    
    printf("After copy : %s",b);
    printf("\n");
}