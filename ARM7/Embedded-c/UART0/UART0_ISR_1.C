/**********************************************************
Expt. *** : Receive and re-transmit the char serially UART using interrupt and main line code to control LED with to LPC2129
Platform  : LPC2129 Development Board.
Date      : 11/03/24
**********************************************************/
#include<lpc21xx.h>
#include"A:\Siva\Embedded\ARM7\Header\4bit_lcd.h"

#define LED 1<<17
void UART0_INIT(void){
    PINSEL0 |= 0X05;
    U0LCR    = 0X83;
    U0DLL    = 97;
    U0LCR    = 0X03;
}

void UART0_ISR(void) __irq{
    unsigned char temp;
    temp = U0IIR;
    if ((U0LSR&1)==1)
		{
			U0THR = U0RBR;
			LCD_DATA(U0RBR);	
    }
    VICVectAddr =0;
}

void UART0_ISR_CONFIG(void){
    VICIntSelect = 0;
    VICVectCntl0 = 1<<5 | 6;
    VICVectAddr0 = (int)UART0_ISR;
    U0IER        = 3<<0;
    VICIntEnable = 1<<6;
}

int main(){
    IODIR0 = LED;
    UART0_INIT();
		LCD_INIT();
    UART0_ISR_CONFIG();
    while(1){
        IOSET0 = LED;
        delay_milisec(500);
        IOCLR0 = LED;
    }
}
