#define C0 (IOPIN0 &(1<<12))
#define C1 (IOPIN0 &(1<<13))
#define C2 (IOPIN0 &(1<<14))
#define C3 (IOPIN0 &(1<<15))

#define R0 1<<16
#define R1 1<<17
#define R2 1<<18
#define R3 1<<19

U8 KEY_LUT[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

U8 KEYSCAN(void){
	U8 ROW_VAL,COL_VAL;
	IODIR0 |= R0|R1|R2|R3;
	
	while(1){
		
		IOCLR0 |= R0|R1|R2|R3;
		IOSET0 |= C0|C1|C2|C3;
		while((C0 && C1 && C2 && C3)==1);
		
		IOCLR0 |= R0;
		IOSET0 |= R1|R2|R3;
		if((C0 && C1 && C2 && C3)==0)
		{
			ROW_VAL =0;
			break;
		}
		
		IOCLR0 |= R1;
		IOSET0 |= R0|R2|R3;
		if((C0 && C1 && C2 && C3)==0)
		{
			ROW_VAL =1;
			break;
		}
		
		IOCLR0 |= R2;
		IOSET0 |= R1|R0|R3;
		if((C0 && C1 && C2 && C3)==0)
		{
			ROW_VAL =2;
			break;
		}
		
		IOCLR0 |= R3;
		IOSET0 |= R1|R2|R0;
		if((C0 && C1 && C2 && C3)==0)
		{
			ROW_VAL =3;
			break;
		}
	}
	
	if(C0==0)
		COL_VAL = 0;
	else if(C1==0)
		COL_VAL = 1;
	else if(C2==0)
		COL_VAL = 2;
	else if(C3==0)
		COL_VAL = 3;
	
		delay_milisec(1000);
	while((C0 && C1 && C2 && C3)==0);
	return KEY_LUT[ROW_VAL][COL_VAL]+48;
}
