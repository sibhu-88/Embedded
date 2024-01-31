#include <stdio.h>
int main()
{
    int b,i,amount = 0;
    
    printf("No. of Bottles : ");
    scanf("%d",&b);
    int a[b];
    
    printf("Each Bottles year of packed : ");
    for(i=0;i<=b-1;i++)
    scanf("%d",&a[i]);
    
    for(int i=1,j=1,k=1;i<=b;i++)
    {
        if (a[i-k]<a[b-j])
            amount += (a[i-k]*i);
        else
        {
            amount += (a[b-j]*i);
            j++, k++;
        }
    }
    
    printf("Amount = %d", amount);
    
    return 0;
}
