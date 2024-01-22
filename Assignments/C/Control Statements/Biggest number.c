 
//WRITE A PROG TO FIND BIGGEST VARABLES IN THREE VARIABLES.

#include<stdio.h>
int main()
{

	int a,b,c;
	printf("ENTER THE A,B &C VALUES ==> ");
	scanf("%d %d %d",&a,&b,&c);

	//CONDITION

	if(a==b&&b==c)
	{
	  printf("All are equal\n");
	}
	else if(a==b&&a>c)
	{
	  printf("A & B is equal bigger then C\n");
	}
	else if(a==c&&c>b)
	{
	  printf("A & C is equal  bigger then B\n");
	}
	else if(b==c&&c>a)
	{
	  printf("B & C is equal bigger then A\n");
	}

	else if(b<a&&c<a)
	{
	  printf("A is biggest\n");
	}
	else if(c<b)
	{
	  printf("B is biggest\n");
	}
	else 
	printf("C is biggest\n");

}
