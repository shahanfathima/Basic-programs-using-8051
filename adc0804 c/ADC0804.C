#include<regX52.h>

#define input P2                                              //Input port (read values of ADC)

#define output P3                                           // Output port (connected to LED's)

void delay(unsigned intmsec );

void adc();

sbit wr= P1^2;                                                    // Write pin.

sbit rd= P1^1;                                                     // Read pin.

sbit intr= P1^3;                                   // Interrupt pin.
void main()

{

input=0xff;                                                         // Declare port 1 as input port.

output=0x00;                                                     // Declare port 0 as output port.

while(1)

{

adc();

  }

}

void delay(unsigned int msec )                   // Delay function

{

int i,j ;

for(i=0;i<msec;i++)

for(j=0; j<1275; j++);

}
void adc()                                                             // Reading values from ADC and display on the LED's

{

rd=1;    

wr=0;    

delay(10);

wr=1;

while(intr==1);

rd=0;

output=input;

delay(10);

intr=1;

}