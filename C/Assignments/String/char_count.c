// wap to find the given char count in the given string.

#include <stdio.h>

void copy(char *, char *);
int main()
{
    char s[20], b;
    int count = 0, i;

    printf("Enter the string : ");
    scanf("%[^\n]", s);

    printf("Enter the string : ");
    scanf(" %c", &b);

    for (i = 0; s[i]; i++)
    {
        if (s[i] == b)
            count++;
    }

    printf("%c ----> %d\n", b, count);
}