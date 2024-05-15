#include <LPC21xx.H>
#include "header.h"
void delay_ms(u32 ms)
{
	T0PR=60000-1;//for 1ms @ PCLK=60MHz
	T0PC=T0TC=0x0;
	T0TCR=0x1;
	while(T0TC<ms);
	T0TCR=0x0;
}
