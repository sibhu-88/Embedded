//WAPT strchr function

#include<stdio.h>
#include<string.h>

char *str_str(char *,char *);
int main() {
    char m[50],s[50];
    int n;

    printf("Enter the main string : ");
    scanf("%[^\n]",m);

    printf("Enter the sub string : ");
    scanf(" %[^\n]",s);

    printf("string base address ==> %p  \n",m);
    printf("\n");

    char *p = str_str(m,s);
    
    if (p == NULL)
    printf("substring not available");
    else
    printf("substring is available ==> %p ",p);
    printf("\n\n");
    
}

/*
char *str_str(char *m,char *s)
{
    int i,j;
    for ( i = 0; m[i]; i++)
    {    
        if (s[0]==m[i])
        {
            for ( j = 1; s[j] ; j++)
            {
                if(s[j]!=m[i+j])
                break;
            }
            if (s[j]=='\0')
            return m+i;
        }
    }
    return NULL;
}
*/


char *str_str(char *m,char *s)
{
    int i,j;
    for ( i = 0; m[i]; i++)
    {    
        if ((s[0]==m[i]))
        {
            if(strncmp(m+i,s,strlen(s))==0)
            return m+i;
        }
    }
    return NULL;
}