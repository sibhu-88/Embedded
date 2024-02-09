//WAPT ADDITION B/W TWO MATRIX AND STORE THE RESY INTO 3RD MATRIX

#include<stdio.h>

int main()
{
    int i,j,a[3][3],b[3][3],c[3][3]={};


    printf("Enter the elements \n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        scanf("%d",&a[i][j]);
    }
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        scanf("%d",&b[i][j]);
    }

    for ( i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            int sum = 0;
            for ( j = 0; j < 3; j++)
            sum += a[i][j]*b[j][k];
            
            c[i][k] = sum;
        }
    }


    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        printf("%d ",c[i][j]);

        printf("\n");
    }
    

}