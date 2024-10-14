#include <LPC21xx.H>

#include "4bit_lcd.h"
#include "typedef.h"

#define LED 1<<17

void RTC_GetTime(U32 *hour, U32 *minute, U32 *second) {

    *hour = HOUR;
    *minute = MIN;
    *second = SEC;
}

void RTC_SetTime(U32 hour, U32 minute, U32 second) {
	HOUR = hour;
	MIN =  minute;
	SEC = second;
}

void RTC_Init(void) {
    CCR = 0X00;
	RTC_SetTime(12, 30, 0);
	CCR |= 0X01;
}

int main() {
    U32 hour, minute, second;

    RTC_Init();
	LCD_INIT();
	IODIR0 = LED;

    while (1) {
        RTC_GetTime(&hour, &minute, &second);
		LCD_STR("Time ::");
		LCD_INTEGER(hour);
		LCD_STR(":");
		LCD_INTEGER(minute);
		LCD_STR(":");
		LCD_INTEGER(second);
		delay_milisec(1000);
		LCD_CMD(0X01);
		IOPIN0 ^= LED;
    }
}


