U8 CGRAM_LUT[] = {
	0X17,
	0X14,
	0X14,
	0X1F,
	0X05,
	0X05,
	0X0D,
	0X00,
	0x0E,
	0X1B,
	0X11,
	0X11,
	0X11,
	0X11,
	0X1F,
	0X00,
	0x0E,
	0X1B,
	0X11,
	0X11,
	0X11,
	0X1F,
	0X1F,
	0X00,
	0x0E,
	0X1B,
	0X11,
	0X11,
	0X1F,
	0X1F,
	0X1F,
	0X00,
	0x0E,
	0X1B,
	0X11,
	0X1F,
	0X1F,
	0X1F,
	0X1F,
	0X00,
	0x0E,
	0X1B,
	0X1F,
	0X1F,
	0X1F,
	0X1F,
	0X1F,
	0X00,
	0x0E,
	0X1E,
	0X1F,
	0X1F,
	0X1F,
	0X1F,
	0X1F,
	0X00,
};

void lcd_symbole(U8, U8);
void CGRAM_WRITE(U8);

void lcd_symbole(U8 byte, U8 symbol)
{
	CGRAM_WRITE(byte);
	lcd_cmd(0X80);
	lcd_display(symbol);
}

void CGRAM_WRITE(U8 nbyte)
{
	U8 i;
	lcd_cmd(0X40);
	for (i = 0; i < nbyte; i++)
		lcd_display(CGRAM_LUT[i]);
}
