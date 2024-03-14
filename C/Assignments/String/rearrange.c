// WAPT rearrange the words in reverse of string line

#include <stdio.h>
#include <string.h>

int main()
{
    char s[20], b[20];
    int i, j, k, temp, c = 0;

    printf("Enter the string : ");
    scanf("%[^\n]", s);

    int l = strlen(s);
    for (i = 0; i <= l; i++)
    {
        if ((s[i] == ' ') || s[i] == '\0')
        {
            for (k = i - 1, j = c; j <= k; j++, k--)
            {
                temp = s[k];
                s[k] = s[j];
                s[j] = temp;
            }
            c = i + 1;
        }
    }
    printf("before Re_arange the reverse string ==> %s", s);
    printf("\n");

    for (i = 0, j = l - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    printf("after Re_arange the reverse string ==> %s", s);
    printf("\n");
}
