//WAPT strncat function

#include<stdio.h>

void str_cat(char *,char *,int);
int main() {
    char s[50],b[50];
    int n;

    printf("Enter the string : ");
    scanf("%[^\n]",s);
    
    printf("Enter the string : ");
    scanf(" %[^\n]",b);

    printf("Enter the numer of string want concodinate : ");
    scanf("%d",&n);

    str_cat(b,s,n);

    printf("After concodination ==> %s",b);

    printf("\n");

}

void str_cat(char *b,char *s,int n)
{
    int i,j;
    for (j = 0; b[j]; j++);

    printf("\n");
    for ( i = 0; i<n ; i++)
    b[j+i]=s[i];
}