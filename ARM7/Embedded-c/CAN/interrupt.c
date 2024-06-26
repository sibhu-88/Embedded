#include <LPC21xx.H>
#include "header.h"

unsigned int flag=0;
void CAN1_RX_Handler(void) __irq
{
	flag=1;
	C1CMR=(1<<2);//release rx buffers
	VICVectAddr=0x0;//to finish the isr
}

void config_vic()
{
	VICIntSelect=0x0;//all interrupts are IRQ
	VICVectCntl0=26|(1<<5);
	VICVectAddr0=(unsigned int)CAN1_RX_Handler;
	VICIntEnable|=(1<<26);
}

void enable_can1_rx_interrupt()
{
	C1IER=0x1;//Only CAN1 RX Interrupt is Enabled
}

