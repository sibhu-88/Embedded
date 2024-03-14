// wapt remove non-alphabets(digits,special char) from the given string.

#include <stdio.h>

void non_alp_remove(char *);
int main()
{
    char s[50], ch;
    int n;

    printf("Enter the string : ");
    scanf("%[^\n]", s);

    non_alp_remove(s);
}

void non_alp_remove(char *s)
{
    int i, j;

    for (i = 0; s[i];)
    {
        if (((s[i] >= 65) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122)))
            i++;
        else
            for (j = i; s[j] = s[j + 1]; j++)
                ;
    }

    printf("after removing non-alp ==> %s", s);

    printf("\n");
}