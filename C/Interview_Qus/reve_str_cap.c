#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverse_and_capitalize_each_word(char *input1) {
    char *word_start = NULL;
    char *temp = input1;
    char temp2;

    while (*temp) {
        if (word_start == NULL && isalpha((unsigned char)*temp)) {
            word_start = temp;
        }

        if (*temp == ' ' || *(temp + 1) == '\0') {
            char *end = (*temp == ' ') ? temp - 1 : temp;
            if (word_start) {
                // Reverse the word in place
                char *start = word_start;
                while (start < end) {
                    temp2 = *start;
                    *start++ = *end;
                    *end-- = temp2;
                }
                // Capitalize the first letter of the word
                *word_start = toupper((unsigned char)*word_start);
                word_start = NULL;
            }
        }
        temp++;
    }
}

int main() {
    char str[] = "are you sure you don't want to come for the party?";
    reverse_and_capitalize_each_word(str);
    printf("%s\n", str);
    return 0;
}