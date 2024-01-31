//wap to check the given string is palindrom or not.

#include<stdio.h>

int main() {
    char s[20];
    int i,j,k;

    printf("Enter the string : ");
    scanf("%s",s);

    for ( k = 0; s[k]; k++);
    
    for ( i = 0,j=k-1; i < j; i++,j--)
    {
        if (s[i]!=s[j])
        break;
    }

    if (i==j)
    printf("The Given String is Palindrom\n");
    else
    printf("The Given String is not Palindrom\n");

    return 0;
}