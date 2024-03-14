// perfect number in between 1 to 100000.

#include <stdio.h>

int main()
{
  int i, sum, num = 1, num1 = 100000;

  for (i = num; i <= num1; i++)
  {
    sum = 0;
    for (int j = 1; j < i; j++)
    {
      if (i % j == 0)
        sum += j;
    }
    if (sum == i)
      printf("%d, ", sum);
  }
  return 0;
}