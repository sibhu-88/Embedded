// WRITE AN ECP TO RECIVING CHARACTER SERIALLY THROUGH UART0 OF LPC2129.
#include <LPC21XX.H>
#include "A:\Siva\Embedded\ARM7\Header\4bit_lcd.h"
#include "A:\Siva\Embedded\ARM7\Header\typedef.h"

// Function prototypes
void UART0_INIT(void);
void UART0_TX(unsigned char);
unsigned char UART0_RX(void);
void UART0_STR(unsigned char *);

int main()
{
    unsigned char rxbyte;
    UART0_INIT();
    while (1)
    {
        rxbyte = UART0_RX();
        LCD_DATA(rxbyte);
    }
}

// Initialize UART0
void UART0_INIT(void)
{
    PINSEL0 = 0x05; // Enable UART0 on pins P0.0 (TXD0) and P0.1 (RXD0)
    U0LCR = 0x83;   // Set DLAB to access DLL and DLM registers
    U0DLL = 97;     // Set baud rate to 9600 (for 15MHz PCLK)
    U0LCR = 0x03;   // Clear DLAB to lock baud rate setting
}

// Transmit a character via UART0
void UART0_TX(unsigned char D)
{
    while (!(U0LSR & (1 << 5)))
        ;      // Wait until THR is empty
    U0THR = D; // Transmit the character
}

// Receive a character via UART0
unsigned char UART0_RX(void)
{
    while (!(U0LSR & (1 << 0)))
        ;         // Wait until RBR has valid data
    return U0RBR; // Return received character
}

// Transmit a string via UART0
void UART0_STR(unsigned char *S)
{
    while (*S != '\0')
    {
        UART0_TX(*S++); // Transmit each character of the string
    }
}
