#include <stdio.h>
#include <string.h>

// Function prototypes
char *removeNonAlpha(char *);
char *convertToUpper(char *);
char *bubbleSort(char *);

int main() {
    char s1[100], s2[100];

    printf("Enter the first string: ");
    scanf("%[^\n]", s1);  // Added input validation
    printf("Enter the second string: ");
    scanf(" %[^\n]", s2); // Added input validation

    if (strlen(removeNonAlpha(s1)) == strlen(removeNonAlpha(s2))) {
        int result = strcmp(bubbleSort(convertToUpper(removeNonAlpha(s1))),
                            bubbleSort(convertToUpper(removeNonAlpha(s2))));

        if (result == 0)
        printf("The given strings are anagrams.\n");
        else
        printf("The given strings are not anagrams.\n");
    } else {
    printf("The given strings are not anagrams.\n");
    }

    return 0;
}

char *removeNonAlpha(char *s) {
    int i, j;

    for (i = 0, j = 0; s[i]; i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0'; // Null-terminate the modified string
    return s;
}

char *convertToUpper(char *s) {
    int i;

    for (i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
        s[i] = s[i] - 32; // Convert to uppercase
        }
    }
    return s;
}

char *bubbleSort(char *s) {
    int i, j;
    char temp;

    for (i = 0; s[i]; i++) {
        for (j = 0; j < strlen(s) - (i + 1); j++) {
            if (s[j] > s[j + 1]) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    return s;
}