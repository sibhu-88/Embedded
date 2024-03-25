#define NUMBER "+919488289487" // Define recipient phone number //In atd mode remove +91

// Function prototypes
void GSM_SMS(U8 *, U8 *);
U8 P[4],G_OTP[4];
void GSM(char *otp)
{
    // Declare variables at the beginning of the function
    U32 x,i=0;
   	while(i++<10000);
    // Generate random number
    srand(T1TC);
    x = rand() % (9999-1000)+1000;
	sprintf(otp,"%d",x);
    // Send SMS
    GSM_SMS(NUMBER,otp);
    // Infinite loop to prevent the program from exiting
//    while (1);
}

// Send SMS using GSM module
void GSM_SMS(U8 *num1, U8 *msg)
{
    delay_sec(1);
    // Send "AT" command to check connection
    UART_STR("AT\r\n");
    delay_sec(2); // Delay to allow GSM module to process command
	
 //	UART_STR("ATD9488289487;\r\n");
 //	delay_sec(2);
    // Set SMS text mode
    UART_STR("AT+CMGF=1\r\n");
    delay_sec(2);

    // Send recipient's phone number
    UART_STR("AT+CMGS=\"");
    UART_STR(num1);// Send each character of the phone number
    UART_STR("\"\r\n"); // End of phone number
	delay_milisec(250);

    // Send message content
    UART_STR("Your Login OTP is -> ");
    UART_STR(msg); // Send each character of the message
     UART_TX(0x1A); // End of message transmission (Ctrl+Z)
}
