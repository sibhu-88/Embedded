//WAPT strchr function

#include<stdio.h>

void str_chr(char *,char );
int main() {
    char s[50],ch;
    int n;

    printf("Enter the string : ");
    scanf("%[^\n]",s);

    printf("Enter the elemet you want to check address : ");
    scanf(" %c",&ch);

    str_chr(s,ch);
}

void str_chr(char *s,char ch)
{
    int i,j;

    printf("\ngiven string ==> %s \n\n",s);
    printf("string base address ==> %p  \n",s);

    printf("\n");
    for ( i = 0; s[i] ; i++)
    {
        if (ch==s[i])
        {
            printf("The Given element %c address is : %p",ch,s+i); 
            break; 
        }  
    }
    
    printf("\n");
}