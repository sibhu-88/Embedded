#include<LPC21XX.H>
#include"E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\delay.h"

#define LCD 0xff
#define RS 1<<8
#define E 1<<9

void lcd_init( void );
void lcd_cmd(U32);
void lcd_display(U8);
void lcd_str(U8 *);
void lcd_rotation(U8 *);

int main(){

	lcd_init();
//	lcd_display('s');
	lcd_rotation("SIVA");
}

void lcd_init( void ){
	
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

void lcd_str(U8 *C){
	while(*C){
		lcd_display(*C++);
	}
}

void lcd_rotation(U8 *R){
	int i;
	while(1){
		for(i=0; i <= 16; i++)
		{
			lcd_cmd(0x80+i);
			lcd_str(R);
			delay_milisec(500);
		}
	}
}
