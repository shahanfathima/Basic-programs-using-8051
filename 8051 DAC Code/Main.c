#include<reg51.h>
#include "DAC0808.h"

// Define Function Prototypes
void delay_sec(unsigned int);
void delay_us(unsigned int);

// Main function
void main()
{
	P0 = 0x00;		 		// Initialize all ports with a value of zero
	P1 = 0x00;
	P2 = 0x00;
	P3 = 0x00;

	InitDAC();				// Initialize DAC0808 data bus

	while(1)
	{  
		
		P2=0XFF;
		delay_sec(1);					
		P2=0;
		delay_sec(1);	
		
		//Generate_DAC_Voltage(0);		// Generate 1000mV = 1v at output
		//delay_sec(1);					// Two second delay
		//Generate_DAC_Voltage(1000);		// Generate 2000mV = 2v at output
		//delay_sec(1);					// Two second delay
		
	}
}



// Function Purpose: Produce approximate delay in Secs.
void delay_sec(unsigned int d)
{
   unsigned int i;

   for(i=0;i<(d*20);i++)
   		delay_us(50000);
}



// Function Purpose: Produce approximate delay in given uSecs.
void delay_us(unsigned int d)
{
   unsigned int i, limit;
   limit = d/15;

   for(i=0;i<limit;i++);
}

