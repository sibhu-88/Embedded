#include <LPC21XX.H>
#include <stdio.h>
#include <stdlib.h>
#include "A:\Siva\Embedded\ARM7\Project\MLSS\UART.c"

#define NUMBER "+919488289487" // Define recipient phone number //In atd mode remove +91

// Function prototypes
void GSM_SMS(U8 *, U8 *);
U8 *OTP(U32);

void GSM()
{
    // Declare variables at the beginning of the function
    U32 x, y = 1000000;
    
    // Initialize UART
    UART_INIT();
    
    // Generate random number
    srand(x);
    x = rand() % y;

    // Send SMS
    GSM_SMS(NUMBER,OTP(x));

    // Infinite loop to prevent the program from exiting
    while (1);
}

// Send SMS using GSM module
void GSM_SMS(U8 *num1, U8 *msg)
{
    delay_milisec(1000);
    // Send "AT" command to check connection
    UART_STR("AT\r\n");
    delay_milisec(1000); // Delay to allow GSM module to process command

    // Set SMS text mode
    UART_STR("AT+CMGF=1\r\n");
    delay_milisec(1000);

    // Send recipient's phone number
    UART_STR("AT+CMGS=\"");
    while (*num1)
        UART_TX(*num1++); // Send each character of the phone number
    UART_STR("\"\r\n"); // End of phone number
    delay_milisec(1000);

    // Send message content
    UART_STR("Your OTP is -> ");
    while (*msg)
         UART_TX(*msg++); // Send each character of the message
     UART_TX(0x1A); // End of message transmission (Ctrl+Z)
     delay_milisec(1000);
}

U8 *OTP(U32 n)
{
	S8 i = 0;
    U8 *arr = (U8 *)malloc(6 * sizeof(U8)); // Allocate memory for the OTP string

    while (n > 0)
    {
        arr[i++] = n % 10 + 48;
        n = n / 10;
    }
    arr[i] = '\0'; // Null-terminate the string
    return arr;
}

