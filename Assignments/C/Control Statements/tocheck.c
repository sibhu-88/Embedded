//WRITE A PROG TO CHECK THE GIVEN CHAR ALP,DIG OR SPL CHAR
#include<stdio.h>
int main()
{
	char ch;

	printf("Enter your char ==>");
	scanf("%c",&ch);

	if((65<=ch) && (ch<=90))
	printf("You enter the charecter is capital alp\n");
	else if((97<=ch) && (ch<=122))
	printf("You enter the charecter is small alp\n");
	else if((48<=ch) && (ch<=57))
	printf("You enter the charecter is digits\n");
	else
	printf("You enter the charecter is speacel char\n");
}
