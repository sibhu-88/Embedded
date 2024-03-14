#include <LPC21xx.H>
#include "./delay.h"
#include "./typedef.h"
#include "./4bit_lcd.h"

#define SW 14
#define READPIN(VAR, BIT) ((VAR >> BIT) & 1)

int main()
{
	int SCNT = 0;
	LCD_INIT();
	LCD_STR("SWITCH COUNT : ");
	while (1)
	{
		if (READPIN(IOPIN0, SW) == 0)
		{
			SCNT++;
			delay_milisec(150);
			LCD_CMD(0XC7);
			LCD_INTEGER(SCNT);
			while (READPIN(IOPIN0, SW) == 0)
				;
		}
	}
}
