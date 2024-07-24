#include <stdio.h>

int main(){
    int arr[6]={10,20,30,10,40,20},arr1[6],i,j,l=0,k=0;

    for ( i = 0; i < 6; i++)
    {
        for (  j = 0; j < 6; j++)
        {
            if (arr[i]==arr[j]) break;
        }
        if (i==j)
        {
            arr1[l++]=arr[i];
        }        
    }

    for ( i = 0; i < l; i++)
    {
       printf("%d\n",arr1[i]);
    }
    
    
}