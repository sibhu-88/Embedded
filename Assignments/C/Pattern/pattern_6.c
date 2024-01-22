#include<stdio.h>
int main()
{
    int i,j,n,s;

    printf("Enter the number ");
    scanf("%d",&n);

    for (i = -n; i <= n; i++)
    {
        if(i<0) s=-i;else s=i;

        for ( j = n; j <=0; j--)
        printf("  ");

        for ( i = 0; i < n; i++)
        {
            printf("* ");
        }
        
        
        
        printf("\n");
        
    }
    
}