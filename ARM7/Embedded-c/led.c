#include<LPC21XX.H>
#include"delay.h"

#define LED1 1<<17
#define LED2 1<<18
#define LED3 1<<19

int main(){
	IODIR0 = LED1 | LED2 | LED3;
		while(1)
		{
			IOCLR0 = LED1;
			IOSET0 = LED2 | LED3;
			delay_milisec(1000);
			IOCLR0 = LED2;
			IOSET0 = LED1 | LED3;
			delay_milisec(1000);
			IOCLR0 = LED3;
			IOSET0 = LED2|LED1;
			delay_milisec(1000);			
		}
}
