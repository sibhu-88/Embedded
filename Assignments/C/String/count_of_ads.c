//WAPT count of alphabets, digites & special char

#include<stdio.h>

int main()
{
    char name[20];
    int i,alphabets=0,digites=0,special=0;

    printf("Enter the string : ");
    scanf("%s",name);
    printf("\n\n");

    for ( i = 0; name[i]; i++)
    {
        if ((name[i]>='a'&&name[i]<='z')||('A'<=name[i])&&(name[i]<='Z'))
        {
            alphabets++;
        }
        else if (name[i]>='0'&&name[i]<='9')
        {
        digites++;
        }
        else
        {
        special++;
        }
    }
    

    printf("no.of alphabets     : %d\n",alphabets);
    printf("no.of digites       : %d\n",digites);
    printf("no.of specual char  : %d\n",special);

}