// WRITE A PROG TO NPRINT THE MULTIPLICATION TAB FOR THE GIVEN NUMBER
#include <stdio.h>
int main()
{
	int x, y, a, b, n;
	int i = 0;

	printf("Enter the X & Y number ==> ");
	scanf("%d  %d", &x, &y);
	printf("Enter the need lenth ==> ");
	scanf("%d", &n);

multiple:
	i++;
	if (i <= n)
	{
		a = x * i;
		b = y * i;
		printf("%d * %d = %d\t%d * %d = %d\n", x, i, a, y, i, b);
		goto multiple;
	}
}
