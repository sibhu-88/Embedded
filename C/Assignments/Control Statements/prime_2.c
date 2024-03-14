#include <stdio.h>
int prime_num(int);
int main()
{
  int i = 1, j, count = 0;

  while (count != 100)
  {
    for (j = 2; j < i; j++)
    {
      if ((i % j) == 0)
        break;
    }

    if (j == i)
    {
      printf("%d, ", j);
      count++;
    }
    i++;
  }
  printf("/n");
}
