#include <LPC21xx.H>
#include "header.h"

u32 io_read(u32 port,u32 pin)
{
	u32 status;
	switch(port)
	{
		case PORT0:status=(IOPIN0&(1<<pin))?1:0;break;
		case PORT1:status=(IOPIN1&(1<<pin))?1:0;break;
	}
	return status;
}

void io_write(u32 port,u32 pin,u32 val)
{
	switch(port)
	{
		case PORT0:
						if(val==1)
							IOSET0=(1<<pin);
						else
							IOCLR0=(1<<pin);
						break;
		case PORT1:
						if(val==1)
							IOSET1=(1<<pin);
						else
							IOCLR1=(1<<pin);
						break;				
	}
}

void io_dir(u32 port,u32 pin,u32 dir)
{
	switch(port)
	{
		case PORT0:
						if(dir==OUTPUT)
							IODIR0=(1<<pin);
						else
							IODIR0&=~(1<<pin);
						break;
		case PORT1:
						if(dir==OUTPUT)
							IODIR1=(1<<pin);
						else
							IODIR1&=~(1<<pin);
						break;
	}				
}

