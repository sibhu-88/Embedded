#include<stdio.h>
#include <string.h>

char *Alter_char(char *,char *);

int main(){
    char word1[100],word2[100];
    printf("Enter  the TWO string\n");
    scanf("%s %s",word1,word2);
    char *merged = Alter_char(word1,word2);
    printf("after merged : %s\n",merged);
}

char *Alter_char(char *word1, char *word2) {
    char *merged = malloc(strlen(word1) + strlen(word2) + 1);
    int i, j = 0;

    for (i = 0; word1[i] || word2[i]; i++) {
        if (word1[i]) merged[j++] = word1[i];
        if (word2[i]) merged[j++] = word2[i];
    }
    merged[j] = '\0';

    return merged;
}
