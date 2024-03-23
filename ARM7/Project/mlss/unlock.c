#include <string.h>
#include "EEPROM.h"
#include "gsm.h"
#include "keypad.h"

#define LED1 1<<17
#define LED2 1<<18
#define BUZZER 1<<21
#define M1 1<<5
#define M2 1<<6

U8 P[4],G_OTP[4];
int x;
void UNLOCK(){
	int i=0,j=0,k=0,L=0,PASSWORD[4];
	char E_PASSWORD[4],OTP[4],key=0,E_OTP[4];
	IODIR0 |= LED1 | LED2 | BUZZER | M1 | M2;
	PASSWORD:
	LCD_CMD(0X01);
	LCD_STR("ENTER PASSWORD");
	UART_STR("ENTER PASSWORD\r\n");
	LCD_CMD(0XC0);
	
	i=0;
	key=KEYSCAN();
	while((key=KEYSCAN())!=':')
	{
		UART_TX(key);
		E_PASSWORD[i++]=key;
		LCD_DATA('*');		
	}
	E_PASSWORD[i]='\0';
	key=KEYSCAN();
//	UART_STR("\r\n");
//	UART_STR(E_PASSWORD);
	
  i2c_eeprom_page_write(I2C_EEPROM_SA,0X00,"1234",4);
	i2c_eeprom_seq_read(I2C_EEPROM_SA,0x00,P,4);
//UART_STR("\r\n");
//	UART_STR(P);
	
	if((strcmp(E_PASSWORD,P))==0){
		GSM(G_OTP);
		ENTER_OTP:
		LCD_CMD(0X01);
		LCD_STR("ENTER OTP");
		UART_STR("\r\nENTER OTP\r\n");
	  LCD_CMD(0XC0);
		j=0;
		key=KEYSCAN();
		while((key=KEYSCAN())!=':')
		{
			E_OTP[j++]=key;
			UART_TX(key);
			LCD_DATA('*');
		}
		E_OTP[j]='\0';
		key=KEYSCAN();
//		
//		UART_STR("\r\n");
//		UART_STR(E_OTP);
//		UART_STR("\r\n");
//		UART_STR(G_OTP);
		
		delay_milisec(1000);		
		
		if((strcmp(E_OTP,G_OTP))==0)
		{
			LCD_CMD(0X01);
			LCD_STR("Door OPENING");
			UART_STR("\r\nDoor OPENING\r\n");
			IOSET0 = BUZZER |M1;
			IOCLR0 =M2;
			delay_sec(2);
			IOCLR0 = BUZZER;
			IOCLR0 = M1|M2;
			delay_sec(5);
			LCD_CMD(0X01);
			LCD_STR("Door CLOSING");
			UART_STR("\r\nDoor CLOSING\r\n");
			IOSET0 = M2|BUZZER;
			IOCLR0 = M1;
			delay_sec(2);
			IOCLR0 = BUZZER;
			IOCLR0 = M1|M2;
			delay_sec(2);
			LCD_CMD(0X01);
			LCD_STR("THANK YOU");
			UART_STR("THANK YOU");
		}
		else
			{
				L++;
				LCD_CMD(0X01);
				LCD_STR("OTP is wrong");
				UART_STR("\r\nOTP is wrong\r\n");
				while(L!=3)
				goto ENTER_OTP;
				while(L==3)
				{
					LCD_CMD(0X01);
					LCD_STR("GO AWAY YOUR WRONG PERSION");
					UART_STR("GO AWAY YOUR WRONG PERSION\r\n");
					while(1);
				}
		}
	}
	else
	{
		k++;
		LCD_CMD(0X01);
		LCD_STR("Password is wrong");
		UART_STR("Password is wrong\r\n");
		
		while(k!=3)
		goto PASSWORD;
		
		while(k==3)
		{
			LCD_STR("WAIT 5 SEC....-> ");
			UART_STR("WAIT 5 SEC....-> ");
			for(i=0;i<5;i++)
			{
				LCD_DATA(i+48);				
				UART_TX(i);				
				delay_sec(1);
			}
			UART_STR("\r\n");
			UNLOCK();
		}
	}
		
}
