#include <LPC21xx.H>

#define LED0 1 << 17
// Initialize UART0
void UART0_INIT(void)
{
	PINSEL0 |= 0x05; // Enable UART0 on pins P0.0 (TXD0) and P0.1 (RXD0)
	U0LCR = 0x83;	 // Set DLAB to access DLL and DLM registers
	U0DLL = 97;		 // Set baud rate to 9600 (for 15MHz PCLK)
	U0LCR = 0x03;	 // Clear DLAB to lock baud rate setting
}

void UART0_ISR(void) __irq
{
	U0THR = 'A';
	VICVectAddr = 0;
}

void UART0_ISR_CONFIG()
{
	VICIntSelect = 0;
	VICVectCntl0 = 1 << 5 | 6;
	VICVectAddr0 = (int)UART0_ISR;
	U0IER = 1 << 1;		   // Enable THRE Interrupts.
	VICIntEnable = 1 << 6; // UART0 Interrupt Enable.
}

int main()
{
	IODIR0 = LED0;
	UART0_INIT();
	UART0_ISR_CONFIG();
	U0THR = 'A';
	while (1)
	{
		if ((IOPIN0 >> 14 & 1) == 0)
			IOCLR0 = LED0;
		else
			IOSET0 = LED0;
	}
}
