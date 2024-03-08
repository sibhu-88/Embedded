/**********************************************************
Experiment: Receive strings and re-transfer to display on LCD with LPC2129
Platform: LPC2129 Development Board
Date: 06/03/2024
**********************************************************/

#include <LPC21XX.H>
#include "E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\4bit_lcd.h"

// Function prototypes
void UART0_INIT(void);
void UART0_TX(unsigned char);
void UART0_STR(unsigned char *);
unsigned char UART0_RX(void);
void LCD_DIS(void);

int main() {
	LCD_INIT();
    // Initialize UART0
    UART0_INIT();
	LCD_DIS();
}

void LCD_DIS(void)
{
	U8 rx_char;
	U8 rec[50];
	U8 i=0;
	while(1){
	LCD_CMD(0X80);
		while(1)
		{ 	
			  rx_char= UART0_RX();
	
			  if(rx_char=='\r')
			  {
				rec[i]='\0';
				LCD_CMD(0X01);
				break;
			  }
			  rec[i++] = rx_char;
		}
		UART0_STR(rec);
		LCD_STR(rec);
	}
}

// Initialize UART0
void UART0_INIT(void) {
    PINSEL0 |= 0x05;   // Enable UART0 on pins P0.0 (TXD0) and P0.1 (RXD0)
    U0LCR = 0x83;     // Set DLAB to access DLL and DLM registers
    U0DLL = 97;       // Set baud rate to 9600 (for 15MHz PCLK)
    U0LCR = 0x03;     // Clear DLAB to lock baud rate setting
}

// Transmit a character via UART0
void UART0_TX(unsigned char D) {
    while ((U0LSR >> 5& 1)==0); // Wait until THR is empty
    U0THR = D;                     // Transmit the character
}

// Transmit a string via UART0
void UART0_STR(unsigned char *S) {
    while (*S) {
        UART0_TX(*S++); // Transmit each character of the string, // Move to the next character
    }
}
// Receive a character via UART0
unsigned char UART0_RX(void) {
    while (!(U0LSR & (1 << 0))); // Wait until RBR has valid data
    return U0RBR;                // Return received character
}
