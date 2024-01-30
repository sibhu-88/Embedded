//WAPT strchr function

#include<stdio.h>

char *str_chr(char *,char );
int main() {
    char s[50],ch;
    int n;

    printf("Enter the string : ");
    scanf("%[^\n]",s);

    printf("Enter the elemet you want to check address : ");
    scanf(" %c",&ch);


    printf("\ngiven string ==> %s \n\n",s);
    printf("string base address ==> %p  \n",s);
    printf("\n");

    char *p= str_chr(s,ch);
    if (p==NULL)
    printf("the char doesn't exit");
    else
    printf("The Given element %c address is : %p\n",ch,p);
}

char *str_chr(char *s,char ch)
{
    int i,j;

    for ( i = 0; s[i] ; i++)
    {
        if (ch==s[i])
        return s+i;
    }
    return NULL;
}