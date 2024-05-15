#define PORT0 	0
#define PORT1 	1
#define OUTPUT 	1
#define INPUT 	0	

typedef unsigned int u32;
typedef unsigned char u8;
void can1_tx(u32 ,u32 ,u32 ,u32 ,u32);
void can1_init(void);
void can1_rx(u32 *,u32 *, u32 *, u32 *,u32 *);

u32 io_read(u32,u32);
void io_write(u32,u32,u32);
void io_dir(u32 ,u32 ,u32);
void delay_ms(u32 );

void uart0_hex(u32);
void uart0_string(char *);
void uart0_tx(u8);
void uart0_init(u32);

void enable_can1_rx_interrupt(void);
void config_vic(void);


