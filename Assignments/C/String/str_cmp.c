#include<stdio.h>
//#include<string.h> ==> pre-define fun header file;

char *str_cmp(char *, char *);
int main()
{
    char s1[50],s2[50];

    printf("Enter the s1 string : ");
    scanf("%[^\n]",s1);
    printf("Enter the s2 string : ");
    scanf(" %[^\n]",s2);

    //int rst= strcmp(s1,s2); ==> pre-define function;

    int rst= str_cmp(s1,s2); //==> user-define function;

    if (rst == 0)
    printf("strings are equal");
    else if (rst < 0)
    printf("s1 is small, s2 is greater");
    else
    printf("s1 is greater, s2 is small");

    printf("\n");
}

char *str_cmp(char *s1, char *s2) //==> user-define function;
{
    int i;
    for ( i = 0; s2[i] ; i++)
    {
        if (s1[i]!=s2[i])
        break;
    }

    int rst = s1[i] - s2[i];

    return rst;
}