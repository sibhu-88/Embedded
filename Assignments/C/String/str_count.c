//wap to display the given string count.

#include<stdio.h>

int main() {
    char s[20];
    int count,i,j,n;

    printf("Enter the string : ");
    scanf("%[^\n]",s);

    for ( i = 0; s[i]; i++)
    {
        count=1;
        for ( j = 0; j < i; j++)
        {
            if (s[i]==s[j])
            break;
        }

        if (j==i)
        {
            for (j=i+1; s[j]; j++)
            {
                if (s[i]==s[j])
                count++;
            }
            printf("%c is present ===> %d\n",s[i],count);
        }
    }
    return 0;

}