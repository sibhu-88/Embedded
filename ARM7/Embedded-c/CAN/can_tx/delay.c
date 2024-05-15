#include <LPC21xx.H>

void delay_s(unsigned int s){
	T0PR=6000000-1;
	//T0TC=T0PC=0;
	T0TCR=0x1;
	while(T0TC<s);
	T0TCR=0x03;
	T0TCR = 0x00;
}

