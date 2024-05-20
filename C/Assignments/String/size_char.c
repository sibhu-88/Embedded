#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for the isprint function

int main()
{
    char s[20];
    int count[256] = {0}; // Assuming ASCII characters

    printf("Enter the string : ");
    fgets(s, sizeof(s), stdin);

    for (int i = 0; s[i]; i++)
    {
        count[s[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0 && isprint(i)) // Check if the character is printable
        { 
            printf("%c ----> %d\n", i, count[i]);
        }
    }

    return 0;
}