#include<LPC21XX.H>
#include "delay.h"

#define SEV_SEG 0xff << 2
#define SEG_1 1<<10
#define SEG_2 1<<11
#define SEG_3 1<<12
#define SEG_4 1<<13

U8 SEG_LUT[]={0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90}

void Display_digit(int);

int main()
{
    COUNT();
    // TIMER();
}

void Display_digit(int n)
{
		U32 i;
		IODIR0 = SEG_D|SEG_1|SEG_2|SEG_3|SEG_4;
	
	IOCLR0 = SEG_D;
	IOSET0 = ((SEG_LUT[n/1000])<<2);
	IOCLR0 = SEG_1;			
	delay_milisec(5);
	IOSET0 = SEG_1;
	
	IOCLR0 = SEG_D;
	IOSET0 = ((SEG_LUT[(n/100)%10])<<2);
	IOCLR0 = SEG_2;			
	delay_milisec(5);
	IOSET0 = SEG_2;
	
	IOCLR0 = SEG_D;
	IOSET0 = ((SEG_LUT[(n/10)%10])<<2);
	IOCLR0 = SEG_3;			
	delay_milisec(5);
	IOSET0 = SEG_3;
	
	IOCLR0 = SEG_D;
	IOSET0 = ((SEG_LUT[n%10])<<2);
	IOCLR0 = SEG_4;			
	delay_milisec(5);
	IOSET0 = SEG_4;
}
