#include<stdio.h>
int prime_num(int);
int main()
{
    int i=1,j,count=0;

    while(count!=51)
    {
      for (j = 2; j < i; j++)
      {
        if ((i%j)==0)
          break;
      }

      if (j==i)
      {
        count++;
        if(count==50)
        printf("%d, ",j);
      }
      i++;
    }

    printf("\n");
}

