#include <stdio.h>

int main()
{
	int a[10], i = 0, j, n, count = 0;

	do
	{
		printf("Enter the array value a[%d] = ", i);
		scanf("%d", &a[i]);

		i++;
	} while (i < 5);

	printf("\n");
	printf("Search number : ");
	scanf("%d", &n);

	for (j = 0; j < 5; j++)
	{
		if (a[j] == n)
			count++;
	}

	printf("%d number count is = %d\n", n, count);
}
