#include<LPC21XX.H>
#include"E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\delay.h"

#define LCD 0xff
#define RS 1<<8
#define E 1<<9

void lcd_init( void );
void lcd_cmd(U32);
void lcd_display(U8);

int main(){
	lcd_init();
	lcd_display('S');
}

void lcd_init( void )
{
	IODIR0 = LCD | RS | E;
	lcd_cmd(0X01);
	lcd_cmd(0X02);
	lcd_cmd(0x0c);
	lcd_cmd(0X38);
	lcd_cmd(0x80);
}

void lcd_cmd(U32 C){
	
	IOCLR0 = LCD ;
	IOSET0 = C ;
	IOCLR0 = RS ;
	IOSET0 = E ;
	delay_milisec(2);
	IOCLR0 = E ;
	
}

void lcd_display(U8 C){
	IOCLR0 = LCD ;
	IOSET0 = C ;
	IOSET0 = RS ;
	IOSET0 = E ;
	delay_milisec(2);
	IOCLR0 = E ;
}

