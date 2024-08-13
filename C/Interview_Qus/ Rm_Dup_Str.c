#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "embedded"; // Original string
    char str1[30];          // Array to hold unique characters
    int i, j, l = 0;        // Loop counters and length of unique string
    int k = strlen(str);    // Length of the original string

    for (i = 0; i < k; i++) {
        // Check if str[i] is already in str1
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break; // Duplicate found, break the inner loop
            }
        }
        // If no duplicate was found, add it to str1
        if (i == j) {
            str1[l++] = str[i];
        }
    }

    str1[l] = '\0'; // Null-terminate the unique string
    printf("%s\n", str1); // Print the result

    return 0;
}
