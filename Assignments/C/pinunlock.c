//WRITE APROG TO UNLOCK YOUR PHONE BY ENTER A RIGHT PIN NUMBER , IF USER PIN IS WRONG THEN GIVE 5 CHANCES TO ENTER IT IN A RIGHT WAY! , IF 5 CHANCES ARE COMPLEATED WITH WRONG PIN NUMBER WAIT FOR 30sec TO RE-ENTER THE PIN NUMBER
#include<stdio.h>
#include<unistd.h>
int main()
{
	int root=1212,user,i=0;

	again:
	printf("Enter Your pin number here ==> ");
	scanf("%d",&user);

	if(root==user)
	{
		sleep(1);
		puts("You unlocked the Phone");
	}
	else
	{
		i++;
		if(5>i)
		{
			puts("You Entered the Wrong pin , Try it Again");
			goto again;
		}
		else
		{
			sleep(5);
			goto again;
		}
	}

}
