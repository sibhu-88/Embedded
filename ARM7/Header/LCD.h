#define LCD 0xff
#define RS 1<<8
#define E 1<<9

void lcd_init( void );
void lcd_cmd(U8);
void lcd_display(U8);
void lcd_str(U8 *);
void lcd_integer(S32);
void lcd_float(S32);

void lcd_init( void ){
	IODIR0 = LCD | RS | E;
	lcd_cmd(0X01);
	lcd_cmd(0X02);
	lcd_cmd(0x0c);
	lcd_cmd(0X38);
	lcd_cmd(0x80);
}

void lcd_cmd(U8 C){
	IOCLR0 = LCD ;
	IOSET0 = C ;
	IOCLR0 = RS ;
	IOSET0 = E ;
	delay_milisec(2);
	IOCLR0 = E ;
}

void lcd_display(U8 C){
	IOCLR0 = LCD ;
	IOSET0 = C ;
	IOSET0 = RS ;
	IOSET0 = E ;
	delay_milisec(2);
	IOCLR0 = E ;
}

void lcd_str(U8 *S){
	U8 ct=0;
	while(*S){
		lcd_display(*S++);
		ct++;
		if(ct==16)
			lcd_cmd(0x0c);
	}
}

void lcd_integer(S32 N){
	U8 arr[5];
	S8 i=0;
	if(N==0)
		lcd_display('0');
	else
	{
		if(N<0)
		{
			lcd_display('-');
			N=-N;
		}
		for(N;N>0; N/10)
			arr[i++] = N%10+48;
		for(--i;i>=0;i++)
			lcd_display(arr[i]);
	}
}

void lcd_float(S32 F){
	int temp = F;
	lcd_integer(temp);
	lcd_display('.');
	temp=(F-temp)*100;
	lcd_integer(temp);
}
