//WRITE A PROG TO IMPLEMENT A HAVE CALCULATOR USING ELSE IF LADDER

#include<stdio.h>

int main()
{
	int a,b;
	char ch;
	printf("Enter the value A & B ==> ");
	scanf("%d %d",&a,&b);

	printf("enter the calculater '+,-,*,/,%' ==> ");
	scanf(" %c",&ch);

	if(ch=='*')
	printf("multiple of A & B = %d",a*b);
	else if(ch=='/')
	printf("devistion of A & B = %d",a/b);
	else if(ch=='+')
	printf("addition of A & B = %d",a+b);
	else if(ch=='-')
	printf("subtraction of A & B = %d",a-b);
	else if(ch=='%')
	printf("modules of A & B = %d",a%b);
}
