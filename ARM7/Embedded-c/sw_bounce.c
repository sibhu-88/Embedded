#include <LPC21xx.H>
#include"E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\delay.h"
#include"E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\typedef.h"
#include"E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\4bit_lcd.h"

#define SW 14
#define READPIN(VAR,BIT) ((VAR >> BIT)&1)

int main()
{
	int SCNT=0;
	LCD_INIT();
	LCD_STR("SWITCH COUNT : ");
	while(1)
	{
		if(READPIN(IOPIN0,SW)==0)
		{
			SCNT++;
			delay_milisec(150);
			LCD_CMD(0XC7);
			LCD_INTEGER(SCNT);
			while (READPIN(IOPIN0,SW)==0);
		}

	}
}
