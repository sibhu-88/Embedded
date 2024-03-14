#include <LPC21XX.H>

// Define LEDs and switches
#define LED1 (1 << 17)
#define LED2 (1 << 18)
#define LED3 (1 << 19)

#define SW1 14
#define SW2 15
#define SW3 16

int main()
{
    // Set LED pins as output
    IODIR0 = LED1 | LED2 | LED3;

    while (1)
    {
        // Check each switch
        if (!(IOPIN0 & (1 << SW1)))
        {
            // Switch 1 pressed
            IOCLR0 = LED1;        // Turn off LED1
            IOSET0 = LED2 | LED3; // Turn on LED2 and LED3
        }
        else if (!(IOPIN0 & (1 << SW2)))
        {
            // Switch 2 pressed
            IOCLR0 = LED2;        // Turn off LED2
            IOSET0 = LED3 | LED1; // Turn on LED3 and LED1
        }
        else if (!(IOPIN0 & (1 << SW3)))
        {
            // Switch 3 pressed
            IOCLR0 = LED3;        // Turn off LED3
            IOSET0 = LED2 | LED1; // Turn on LED2 and LED1
        }
        else
        {
            // No switches pressed, turn on all LEDs
            IOSET0 = LED3 | LED2 | LED1;
        }
    }
    return 0;
}
