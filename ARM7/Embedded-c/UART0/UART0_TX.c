// WRITE AN ECP TO TRANSMIT 'A' SERIALLY THROUGH UART0 OF LPC2129.
#include <LPC21XX.H>

// Function prototypes
void UART0_INIT(void);
void UART0_TX(unsigned char);
void UART0_STR(unsigned char *);

int main()
{
    // Initialize UART0
    UART0_INIT();

    // Transmit 'A' character
    UART0_TX('A');

    // Transmit string "Hello" using UART0_STR function
    UART0_STR("Hello");

    return 0;
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

// Transmit a string via UART0
void UART0_STR(unsigned char *S)
{
    while (*S != '\0')
    {
        UART0_TX(*S++); // Transmit each character of the string, // Move to the next character
    }
}
