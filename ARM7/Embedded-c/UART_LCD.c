/**********************************************************
Experiment: Receive strings and re-transfer to display on LCD with LPC2129
Platform: LPC2129 Development Board
Date: 06/03/2024
**********************************************************/

#include <LPC21XX.H> // Include LPC2129 header file
#include "A:\Siva\Embedded\ARM7\Header\4bit_lcd.h" // Include LCD header file

// Function prototypes
void UART0_INIT(void);
unsigned char UART0_RX(void);
void LCD_DISPLAY(void); // Corrected function declaration

int main() {
    // Initialize UART0
    UART0_INIT();

    // To Display Received String on LCD
    LCD_DISPLAY();

    // Infinite loop to prevent the program from exiting
    while (1);
}

// Function to display received string on LCD
void LCD_DISPLAY() {
    unsigned char rec[50]; // Corrected datatype to unsigned char
    unsigned int i = 0;    // Changed datatype to unsigned int

    // Receive characters until newline character
    while (1) {
        unsigned char rx_char = UART0_RX(); // Receive character via UART0

        if (rx_char == '\n') {
            rec[i] = '\0'; // Null-terminate the received string
            break;         // Exit the loop if newline character received
        }

        rec[i++] = rx_char; // Store received character
    }

    LCD_STR(rec); // Display received string on LCD
}

// Initialize UART0
void UART0_INIT(void) {
    PINSEL0 = 0x05; // Enable UART0 on pins P0.0 (TXD0) and P0.1 (RXD0)
    U0LCR = 0x83;   // Set DLAB to access DLL and DLM registers
    U0DLL = 97;     // Set baud rate to 9600 (for 15MHz PCLK)
    U0LCR = 0x03;   // Clear DLAB to lock baud rate setting
}

// Receive a character via UART0
unsigned char UART0_RX(void) {
    while (!(U0LSR & (1 << 0))); // Wait until RBR has valid data
    return U0RBR;                 // Return received character
}
