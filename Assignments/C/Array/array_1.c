#include<stdio.h>

int main()
{
	int a[5],i=0,j;

	do
	{
		printf("Enter the array value a[%d] = ",i);
		scanf("%d",&a[i]);

		i++;
	}while(i<5);

	for(j=0;j<5;j++)
	printf(" a[%d] = %d\n",j,a[j]);

}
