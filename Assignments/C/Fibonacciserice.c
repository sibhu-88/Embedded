//WRITE A PROG TO PRINT 'N' NUMBER OF FIBONACCI SERIES VALUES.

#include<stdio.h>

int main()
{
    int x=0,y=1,z,n,i=0;

    printf("Enter the number you want print continuesly : ");
    scanf("%d",&n);


    for ( i; i < n; i++)
    {
        z=x+y;
        printf("%d, ",x);
        x=y;
        y=z;
    }

    /*
    while (i++,i<=n)
    {
        z=x+y;
        printf("%d ",x);
        x=y;
        y=z;
    }
    */

    /*
        //print continus values
    for ( i; x < n; i++)
    {
        z=x+y;
        printf("%d, ",x);
        x=y;
        y=z;
    }   
*/

    
    printf("\n");
}
