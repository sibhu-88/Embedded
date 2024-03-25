#include <lpc21xx.h>
#include "UART.h"
#include "lcd.h"
#include "unlock.c"

#define SW 15
#define READPIN(VAR,BIT) ((VAR >> BIT)&1) 

U8 P[4],G_OTP[4];
int main(){
	LCD_INIT();
	init_i2c();
	UART_INIT();
	
    T1TCR = 0X01;
	UART_STR("MULTILEVEL SECURITY SYSTEM\r\n");
	LCD_STR("MULTILEVEL SECURITY SYSTEM");
 	while(READPIN(IOPIN0,SW)==1);
	UNLOCK();
//	GSM(G_OTP);
}
