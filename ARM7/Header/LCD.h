#include "typedef.h"

#define LCD 0xFF
#define RS (1 << 8)
#define E (1 << 9)

void lcd_init(void);
void lcd_cmd(U8);
void lcd_display(U8);
void lcd_str(U8 *);
void lcd_integer(S32);
void lcd_float(S32);

void lcd_init(void)
{
    // Set LCD, RS, and E pins as output
    IODIR0 = LCD | RS | E;

    // Initialization sequence
    lcd_cmd(0x01); // Clear display
    lcd_cmd(0x02); // Return home
    lcd_cmd(0x0C); // Display on, cursor off
    lcd_cmd(0x38); // 2 lines, 5x8 matrix
    lcd_cmd(0x80); // Set cursor to line 1
}

void lcd_cmd(U8 C)
{
    IOCLR0 = LCD;     // Clear LCD
    IOSET0 = C;       // Set command
    IOCLR0 = RS;      // Set command mode
    IOSET0 = E;       // Enable LCD
    delay_milisec(2); // Wait
    IOCLR0 = E;       // Disable LCD
}

void lcd_display(U8 C)
{
    IOCLR0 = LCD;     // Clear LCD
    IOSET0 = C;       // Set data
    IOSET0 = RS;      // Set data mode
    IOSET0 = E;       // Enable LCD
    delay_milisec(2); // Wait
    IOCLR0 = E;       // Disable LCD
}

void lcd_str(U8 *S)
{
    U8 ct = 0;
    while (*S)
    {
        lcd_display(*S++);
        ct++;
        if (ct == 16)
            lcd_cmd(0xC0); // Move to second line
    }
}

void lcd_integer(S32 N)
{
    U8 arr[5];
    S8 i = 0;

    if (N == 0)
        lcd_display('0');
    else
    {
        if (N < 0)
        {
            lcd_display('-');
            N = -N;
        }
        while (N > 0)
        {
            arr[i++] = N % 10 + '0';
            N /= 10;
        }
        for (--i; i >= 0; i--)
            lcd_display(arr[i]);
    }
}

void lcd_float(S32 F)
{
    int temp = F;
    lcd_integer(temp);
    lcd_display('.');
    temp = (F - temp) * 100;
    lcd_integer(temp);
}
