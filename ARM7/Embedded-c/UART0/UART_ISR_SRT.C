/**********************************************************
Expt. *** : Receive and re-transmit the char serially UART using interrupt and main line code to control LED with to LPC2129
Platform  : LPC2129 Development Board.
Date      : 14/03/24
**********************************************************/
#include <lpc21xx.h>
#include "A:\Siva\Embedded\ARM7\Header\4bit_lcd.h"

#define LED 1 << 17

void UART0_INIT(void);
void UART0_ISR_CONFIG(void);
void UART0_TX(U8);
void UART0_STR(U8 *);
U8 UART0_RX(void);

U8 temp;
U8 rx_char;
U8 rec[50];
U8 i = 0;
void UART0_ISR(void) __irq
{
    temp = U0IIR;
    if ((U0LSR & 1) == 1)
    {
        rx_char = UART0_RX();

        if (rx_char == '\r')
        {
            rec[i] = '\0';
            LCD_CMD(0X01);
            UART0_STR(rec);
            LCD_STR(rec);
        }
        rec[i++] = rx_char;
    }
    VICVectAddr = 0;
}

int main()
{
    IODIR0 = LED;
    UART0_INIT();
    LCD_INIT();
    UART0_ISR_CONFIG();
    while (1)
    {
        IOSET0 = LED;
        delay_milisec(500);
        IOCLR0 = LED;
        delay_milisec(500);
    }
}

void UART0_INIT(void)
{
    PINSEL0 |= 0X05;
    U0LCR = 0X83;
    U0DLL = 97;
    U0LCR = 0X03;
}

void UART0_ISR_CONFIG(void)
{
    VICIntSelect = 0;
    VICVectCntl0 = 1 << 5 | 6;
    VICVectAddr0 = (int)UART0_ISR;
    U0IER = 3 << 0;
    VICIntEnable = 1 << 6;
}

// Transmit a character via UART0
void UART0_TX(U8 D)
{
    while ((U0LSR >> 5 & 1) == 0)
        ;      // Wait until THR is empty
    U0THR = D; // Transmit the character
}

// Transmit a string via UART0
void UART0_STR(U8 *S)
{
    while (*S)
    {
        UART0_TX(*S++); // Transmit each character of the string, // Move to the next character
    }
}

// Receive a character via UART0
U8 UART0_RX(void)
{
    while (!(U0LSR & (1 << 0)))
        ;         // Wait until RBR has valid data
    return U0RBR; // Return received character
}
