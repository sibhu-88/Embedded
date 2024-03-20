#include "A:\Siva\Embedded\ARM7\Project\MLSS\typedef.h"

void delay_sec(U32 sec)
{
    T0PR = 15000000 - 1;
    T0TCR = 0x01; // Start timer
    while (T0TC < sec)
        ;
    T0TCR = 0x03; // Reset timer
    T0TCR = 0x00; // Stop timer
}

void delay_milisec(U32 ms)
{
    T0PR = 15000 - 1;
    T0TCR = 0x01; // Start timer
    while (T0TC < ms)
        ;
    T0TCR = 0x03; // Reset timer
    T0TCR = 0x00; // Stop timer
}

void delay_microsec(U32 us)
{
    T0PR = 15 - 1;
    T0TCR = 0x01; // Start timer
    while (T0TC < us)
        ;
    T0TCR = 0x03; // Reset timer
    T0TCR = 0x00; // Stop timer
}
