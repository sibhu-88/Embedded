//WRITE A PROG TO  UNLOCK THE PHONE BY ENTER THE PIN NUMBER DISPLAY UPP--- ERROR MESSAGE "PIN NUMBER IS WRONG TRY IT AGAIN"

#include<stdio.h>

int main()
{
        int pin = 3456,pass;

	printf("Enter the Pin number here ==> ");
	scanf("%d",&pass);

	if(pin == pass)
	printf("Welcom to the world\n");
	else
	printf("Sorry, You tried the wrong pin, pleace try it again\n");
}
