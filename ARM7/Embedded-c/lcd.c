#include <LPC21XX.H>  // Include LPC21XX header file
#include "E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\delay.h"  // Include delay header file

int main() {
    // Initialize LCD
    lcd_init();

    // Display 'S' on LCD
    lcd_display('S');

    return 0;
}
