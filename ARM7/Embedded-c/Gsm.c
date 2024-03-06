/**********************************************************
Expt. *** : GSM interfacing with to LPC2129
Platform  : LPC2129 Development Board.
Date      : 06/03/2024
**********************************************************/

#include <LPC21XX.H>
#include "A:\Siva\Embedded\ARM7\Header\delay.h"

#define NUMBER "1234567890" // Define recipient phone number

// Function prototypes
void UART0_INIT(void);
void UART0_TX(unsigned char);
void UART0_STR(const unsigned char *);
void GSM_SMS(unsigned char *, unsigned char *);

int main() {
    // Initialize UART0
    UART0_INIT();

    // Send SMS
    GSM_SMS(NUMBER, "Welcome to the sibhu World");

    // Infinite loop to prevent the program from exiting
    while (1);
}

// Send SMS using GSM module
void GSM_SMS(unsigned char *num1, unsigned char *msg) {
    // Send "AT" command to check connection
    UART0_STR("AT");
    delay_milisec(500); // Delay to allow GSM module to process command

    // Set SMS text mode
    UART0_STR("AT+CMGF=1");
    delay_milisec(500);

    // Send recipient's phone number
    UART0_STR("AT+CMGS=\"");
    while (*num1)
        UART0_TX(*num1++); // Send each character of the phone number
    UART0_TX('"'); // End of phone number
    delay_milisec(500);

    // Send message content
    while (*msg)
        UART0_TX(*msg++); // Send each character of the message
    UART0_TX(0x1A); // End of message transmission (Ctrl+Z)
    delay_milisec(500);
}

// Initialize UART0
void UART0_INIT(void) {
    PINSEL0 = 0x05;   // Enable UART0 on pins P0.0 (TXD0) and P0.1 (RXD0)
    U0LCR = 0x83;     // Set DLAB to access DLL and DLM registers
    U0DLL = 97;       // Set baud rate to 9600 (for 15MHz PCLK)
    U0LCR = 0x03;     // Clear DLAB to lock baud rate setting
}

// Transmit a character via UART0
void UART0_TX(unsigned char D) {
    while (!(U0LSR & (1 << 5))); // Wait until THR is empty
    U0THR = D;                     // Transmit the character
}

// Transmit a string via UART0
void UART0_STR(const unsigned char *S) {
    while (*S != '\0') {
        UART0_TX(*S++); // Transmit each character of the string
    }
}
