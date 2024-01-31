// WAPT conseactive space in a given string line.

#include<stdio.h>

void non_alp_remove(char * );
int main() {
    char s[100],ch;
    int n;

    printf("Enter the string : ");
    scanf("%[^\n]",s);

    non_alp_remove(s);
}

void non_alp_remove(char *s)
{
    int i,j;

    for ( i = 0; s[i]; )
    {
        if ((s[i]==' ')&&(s[i+1]==' '))
        for ( j = i; s[j]=s[j+1]; j++);
        else
        i++;
    }

    printf("after removing spaces ==> %s",s);

    printf("\n");
    
}