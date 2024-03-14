#include <LPC21xx.H>
#include "E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\delay.h"
#include "E:\v23ce5s9\SIVA\ARM\EMBEDDED\Header\typedef.h"

#define SEG_D 0XFF << 2
#define SEG_1 1 << 10
#define SEG_2 1 << 11
#define SEG_3 1 << 12
#define SEG_4 1 << 13

U8 SEG_LUT[] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};
// If we need float means use ^128 . needed seg.

void TIMER(void);
void COUNT(void);
void Display_digit(int, int, int, int);
int main()
{
    while (1)
        TIMER();
}

void Display_digit(int i, int j, int k, int l)
{
    U8 dly;
    IODIR0 = SEG_D | SEG_1 | SEG_2 | SEG_3 | SEG_4;
    for (dly = 0; dly < 50; dly++)
    {
        IOCLR0 = SEG_D;
        IOSET0 = ((SEG_LUT[i]) << 2);
        IOCLR0 = SEG_1;
        delay_milisec(5);
        IOSET0 = SEG_1;

        IOCLR0 = SEG_D;
        IOSET0 = ((SEG_LUT[j] ^ 128) << 2);
        IOCLR0 = SEG_2;
        delay_milisec(5);
        IOSET0 = SEG_2;

        IOCLR0 = SEG_D;
        IOSET0 = ((SEG_LUT[k]) << 2);
        IOCLR0 = SEG_3;
        delay_milisec(5);
        IOSET0 = SEG_3;

        IOCLR0 = SEG_D;
        IOSET0 = ((SEG_LUT[l]) << 2);
        IOCLR0 = SEG_4;
        delay_milisec(5);
        IOSET0 = SEG_4;
    }
}

void COUNT(void)
{
    int i, j, k, l;
    IODIR0 = SEG_D | SEG_1 | SEG_2 | SEG_3 | SEG_4;

    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            for (k = 0; k <= 9; k++)
            {
                for (l = 0; l <= 9; l++)
                {
                    Display_digit(i, j, k, l);
                }
            }
        }
    }
}

void TIMER(void)
{
    int i, j, k, l;
    IODIR0 = SEG_D | SEG_1 | SEG_2 | SEG_3 | SEG_4;

    for (i = 0; i <= 5; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            for (k = 0; k <= 5; k++)
            {
                for (l = 0; l <= 9; l++)
                {
                    Display_digit(i, j, k, l);
                }
            }
        }
    }
}
