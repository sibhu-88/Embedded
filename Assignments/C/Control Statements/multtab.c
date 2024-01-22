//WRITE A PROG TO NPRINT THE MULTIPLICATION TAB FOR THE GIVEN NUMBER
#include<stdio.h>
int main()
{
	int x,y,z,n;
	int i=0;

	printf("Enter the X number ==> ");
	scanf("%d",&x);
	printf("Enter the need lenth ==> ");
	scanf("%d",&n);

	multiple:
	i++;
	if(i<=n)
	{
		y=i;
		z=x * y;
		printf("%d * %d = %d\n",x,y,z);
		goto multiple;
	}
}
