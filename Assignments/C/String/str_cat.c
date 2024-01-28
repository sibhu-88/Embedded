//WAPT strcat function

#include<stdio.h>

void str_cat(char *,char *);
int main() {
    char s[50],b[50];

    printf("Enter the string : ");
    scanf("%[^\n]",s);
    
    printf("Enter the string : ");
    scanf(" %[^\n]",b);

    str_cat(b,s);

    printf("After concatination ==> %s",b);

    printf("\n");

}

void str_cat(char *b,char *s)
{
    int i,j;
    for (j = 0; b[j]; j++);

    printf("\n");
    for ( i = 0; s[i] ; i++)
    b[j+i]=s[i];
}