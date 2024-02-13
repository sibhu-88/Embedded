#include<LPC21XX.H>
#include<string.h>
#include"Header\delay.h"

#define LCD 0xff
#define RS 1<<8
#define E 1<<9

void LCD_Init( void );
void LCD_Cmd(U8);
void LCD_Display(U8);
void LCD_Str(U8 *);
void LCD_Rotation(U8 *);


int main(){
	LCD_Init();
	LCD_Rotation('S');
}

void LCD_Init( void )
{
	IODIR0 = LCD | RS | E;
	LCD_Cmd(0X01);
	LCD_Cmd(0X02);
	LCD_Cmd(0x0c);
	LCD_Cmd(0X38);
	LCD_Cmd(0x80);
}

void LCD_Cmd(U32 C){
	
	IOCLR0 = LCD ;
	IOSET0 = C ;
	IOCLR0 = RS ;
	IOSET0 = E ;
	delay_milisec(2);
	IOCLR0 = E ;
	
}

void LCD_Display(U8 D){
	IOCLR0 = LCD ;
	IOSET0 = D ;
	IOSET0 = RS ;
	IOSET0 = E ;
	delay_milisec(2);
	IOCLR0 = E ;
}

void LCD_Str(U8 *S)
{
    while (*S)
    LCD_Display(*S++);
}

void LCD_Rotation(U8 *R)
{
    int i;
    while (1)
    {
       for ( i = 0; i <= 16; i++)
       {
            LCD_Str(*R);
       }
       if (i==17)
       {
            LCD_Cmd(0x80);
            for ( i = strlen(R); i >= 0 ; i--)
            LCD_Display(*R[i]);    
       }
    }
}