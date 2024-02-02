//WAPT strchr function

#include<stdio.h>

char *str_rchr(char *,char );
int main() {
    char s[50],ch;
    int n;

    printf("Enter the string : ");
    scanf("%[^\n]",s);

    printf("Enter the elemet you want to check address : ");
    scanf(" %c",&ch);

    printf("given string ==> %s \n",s);
    printf("string base address ==> %p  \n",s);

    char *p = str_rchr(s,ch);

    printf("The Given element %c address is : %p",ch,p); 
    printf("\n");
    
}

char *str_rchr(char *s,char ch)
{
    int i,j;

    for ( i = 0; s[i]; i++);
    for ( j = i-1; j>=0; j--)
    {
        if (ch==s[j])
        return s+j;
    }
    return NULL;
}
