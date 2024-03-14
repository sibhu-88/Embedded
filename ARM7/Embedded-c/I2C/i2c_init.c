/**********************************************************
Expt. *** : I2C Init with to LPC2129
Platform  : LPC2129 Development Board.
Date      : 11/03/24
**********************************************************/
#include<lpc21xx.h>

void I2C_INIT(void){
    PINSEL0 |= 0X50; /* Configure P0.2 and P0.3 as SCL0 and SDA0 respectively */
    I2CONSET = 0X40; /* Enable I2C  */
}

void I2C_START(void){
    I2CONSET = 0X20; /* Set Start bit for Start condition */
    while (((I2CONSET>>3) &1)==0); /* Wait till SI = 1 */
    I2CONSET = 0X28; /* Clear Start bit and SI bit */
}

void I2C_WRITE(char data){
    I2DAT = data;
    while(((I2CONSET >>3)&1)==0);
    I2CONSET = 0X08; /* Clear SI bit */
}

void I2C_STOP(void){
    I2CONSET = 0X50; /* Set Stop bit for Stop condition */
}

int main(){
	I2C_INIT();
    I2C_START();
    I2C_WRITE();
}
