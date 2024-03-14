#include <LPC21XX.H>
#include "./delay.h"

#define LED1 (1 << 17)
#define LED2 (1 << 18)
#define LED3 (1 << 19)

int main()
{
    // Set LED pins as output
    IODIR0 = LED1 | LED2 | LED3;

    while (1)
    {
        // Blink LED1
        IOCLR0 = LED1;        // Turn off LED1
        IOSET0 = LED2 | LED3; // Turn on LED2 and LED3
        delay_milisec(1000);  // Delay for 1000 milliseconds

        // Blink LED2
        IOCLR0 = LED2;        // Turn off LED2
        IOSET0 = LED1 | LED3; // Turn on LED1 and LED3
        delay_milisec(1000);  // Delay for 1000 milliseconds

        // Blink LED3
        IOCLR0 = LED3;        // Turn off LED3
        IOSET0 = LED2 | LED1; // Turn on LED2 and LED1
        delay_milisec(1000);  // Delay for 1000 milliseconds
    }
}