#include<LPC21XX.H>

#define LED1 1<<17
#define LED2 1<<18
#define LED3 1<<19

#define SW1 14
#define SW2 15
#define SW3 16

int main()
{
	IODIR0 = LED1| LED2 | LED3;
	while(1)
	{
		if((IOPIN0>>SW1&1)==0)
		{
			IOCLR0 = LED1;
			IOSET0 = LED2 | LED3;
		}
		else if((IOPIN0>>SW2&1)==0)
		{
			IOCLR0 = LED2;
			IOSET0 = LED3 | LED1;
		}
		else if((IOPIN0>>SW3&1)==0)
		{
			IOCLR0 = LED3;
			IOSET0 = LED2 | LED1;;
		}
		else
		{
			IOSET0 = LED3 | LED2 | LED1;
		}
	}
}
