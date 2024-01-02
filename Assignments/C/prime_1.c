
#include<stdio.h>
int prime_num(int);
int main()
{
    int num=1,num1=100,i;

    for(i=num;i<=num1;i++)
    prime_num(i);

    printf("\n");
}

int prime_num(int x)
{
    int i;
    for (i = 2; i < x; i++)
    {
        if ((x%i)==0)
        break;
    }
	if(i==x)
	printf("%d, ",x);
}
