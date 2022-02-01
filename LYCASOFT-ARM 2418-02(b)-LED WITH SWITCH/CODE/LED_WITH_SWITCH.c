#include <lpc214x.h>   

#define LED_1	0
#define SW_1	1

int main() 
{
    unsigned int  SW_1_Status;
	
    PINSEL0 = 0x00000000;
    IODIR0 = ((1<<LED_1) | (0<<SW_1));				// LED pin as output and Switch Pin as input 

		IOPIN0 = 0X00000000;
	
		while(1)
		{
       SW_1_Status = (IOPIN0>>SW_1) & 0x01 ;	// Read the switch status
       
       if(SW_1_Status == 1)										//Turn ON/OFF LEDs depending on switch status
       {  
         IOPIN0 = (1<<LED_1);
       }
       else
       {
         IOPIN0 = (0<<LED_1);
       }      
    }
}