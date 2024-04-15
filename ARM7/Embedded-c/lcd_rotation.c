#include<LPC21XX.H>
#include<string.h>
#include "A:\Siva\Embedded\ARM7\Header\4bit_lcd.h"

int main(){
	LCD_Init( );
	LCD_Rotation("SIVA");
}

void LCD_Rotation(U8 *R)
{
	int l=strlen(R)-1;
	int i;
    while (1)
    {
       for ( i = 0; i <= 16; i++)
       {	LCD_Cmd(0x01);
					LCD_Cmd(0x80+i);
          LCD_Str(R);
					delay_milisec(500);
			 }
			 
			 for ( i = 0; l>0; i++,l--)
       {	
				 LCD_Cmd(0x01);
				 LCD_Cmd(0x80+i);
        		 LCD_Str(R);
				 LCD_Cmd(0x80);
				 LCD_Str(R+1);
				 delay_milisec(500);
			 }
    }
}
