#include<LPC21XX.H>
#include "delay.h"

#define SEV_SEG 0xff << 2
#define SEG_1 1<<10
#define SEG_2 1<<11
#define SEG_3 1<<12
#define SEG_4 1<<13

U8 SEG_LUT[]={0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90}

void COUNT(void);
void TIMER(void);

int main()
{
    COUNT();
    // TIMER();
}

void COUNT(void)
{
    int i,j,k,l;
    IODIR0 = SEV_SEG | SEG_1 | SEG_2 | SEG_3 | SEG_4;

    for ( i = 0; i <= 9; i++)
    {
        IOCLR0 = SEV_SEG;
        IOSET0 = (SEG_LUT[i]<<2);
        IOCLR0 = SEG_1;
        delay_milisec(5);
        IOSET0 = SEG_1;
        for ( j = 0; j <= 9; j++)
        {
            IOCLR0 = SEV_SEG;
            IOSET0 = (SEG_LUT[j]<<2);
            IOCLR0 = SEG_2;
            delay_milisec(5);
            IOSET0 = SEG_2;
            for ( k = 0; k <= 9; k++)
            {
                IOCLR0 = SEV_SEG;
                IOSET0 = (SEG_LUT[k]<<2);
                IOCLR0 = SEG_3;
                delay_milisec(5);
                IOSET0 = SEG_3; 
                for ( l = 0; l <= 9; l++)
                {
                    IOCLR0 = SEV_SEG;
                    IOSET0 = (SEG_LUT[l]<<2);
                    IOCLR0 = SEG_4;
                    delay_milisec(5);
                    IOSET0 = SEG_4;
                }               
            }
        }
    }
}

void TIMER(void)
{

}