//WRITE A PROG TO  CONVERT THE GIVEN ALPHABET INTO IS OPPOSITE CASE USING BITWISE OPERATOR AND ALSO ARTHAMETIC OPERATION "IF IT'S NON-ALPHABET DISPLAY ERROR MESSAGE AS 'GIVEN CHAR IS NON-ALPHAABET'".

#include<stdio.h>
int main() {
    char ch;

    printf("Enter the Alphabet : ");
    scanf("%c", &ch);

    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        ch ^= (1 << 5); // Toggle the 5th bit to convert case
        printf("%c\n", ch);
    } else {
        printf("PLEASE CHECK THE GIVEN CHAR IS NON-ALPHABET\n");
    }
    
    return 0;

}