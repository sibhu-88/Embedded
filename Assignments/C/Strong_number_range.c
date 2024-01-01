
#include<stdio.h>

int main()
{
    int num=1,num1=100000,n,j,i,factorial,rem,total;
    for(i=num;i<=num1;i++)
    {
      total=0;
      n=i;
      while (n!=0) 
      {
      	  rem=n%10;
          n/=10;
          factorial = 1;
          for (j=1; j <= rem; j++)
          factorial *= j;

          total +=factorial;
      }

      if (i==total)
      printf("%d, ",i);
    }

    printf("\n");

    return 0;
}
