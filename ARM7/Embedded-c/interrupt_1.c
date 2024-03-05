#include<LPC21XX.H>
#define LED 1<<0;

void EXTINT0_ISR (void) __irq
{
	EXTINT =0X01;
	IOSET0 = LED;
	IOCLR0 = LED;
	VICVectAddr = 0;
}

int main()
{
	unsigned int cnt =0;
	PINSEL1 = 0X01;
	IODIR0 = LED;
	VICIntSelect = 0;
	
	VICVectCntl0 = 1<<5 | 14;
	VICVectAddr0 = (int)EXTINT0_ISR;
	
	EXTMODE = 0X00;
	EXTPOLAR = 0X00;
	
	VICIntEnable = 1<<14;
	
	while(1)
		cnt++;
}
