#include<stdio.h>
#include<string.h> ==> pre-define fun header file;

int main()
{
    char s1[50],s2[50];
    int n;

    printf("Enter the s1 string : ");
    scanf("%[^\n]",s1);
    printf("Enter the s2 string : ");
    scanf(" %[^\n]",s2);
    printf("Enter the n value : ");
    scanf(" %d",&n);

    //int rst= strncmp(s1,s2,n); //==> pre-define function;
    int rst= strncmp(s1,s2,n); //==> user-define function;

    if (rst == 0)
    printf("strings are equal %d",rst);
    else if (rst < 0)
    printf("s1 is small, s2 is greater %d",rst);
    else
    printf("s1 is greater, s2 is small %d",rst);

    printf("\n");
}

char *str_cmp(char *s1, char *s2, int n) //==> user-define function;
{
    int i;
    for ( i = 0; (i < n )&&s1[i]&&s2[i]; i++)
    {
        if (s1[i]!=s2[i])
        break;
    }

    if (i==n)
    return 0;
    else
    return s1[i] - s2[i];
}
