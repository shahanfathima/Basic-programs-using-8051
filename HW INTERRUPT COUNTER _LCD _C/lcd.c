#include<REGX52.H>
#include<stdio.h>

#define LcdDataBus P2 
sbit LCD_RS = P2^0; 
sbit LCD_RW = P2^1;
 sbit LCD_EN = P2^2;
 
  
 void Lcd_CmdWrite(char cmd);
 void Lcd_DataWrite(char dat);
 void delay(int cnt);
 
 int count=0;
 
 void delay(int cnt)
 { int i; 
for(i=0;i<cnt;i++);
 } 

void lcd_data_string(unsigned char *str);
 
 void Lcd_DataWrite(char dat)
 { 
LcdDataBus = (dat & 0xF0); //Send higher nibble 
LCD_RS = 1; // Send HIGH pulse on RS pin for selecting data register 
LCD_RW = 0; // Send LOW pulse on RW pin for Write operation
 LCD_EN = 1; // Generate a High-to-low pulse on EN pin delay(1000); 
LCD_EN = 0; 
delay(10000); 
LcdDataBus = ((dat<<4) & 0xF0); //Send Lower nibble 
LCD_RS = 1; // Send HIGH pulse on RS pin for selecting data register LCD_RW = 0; // Send LOW pulse on RW pin for Write operation 
LCD_EN = 1; // Generate a High-to-low pulse on EN pin 
delay(1000); 
LCD_EN = 0; delay(10000); 
}



 
 void Lcd_CmdWrite(char cmd) 
{ 
LcdDataBus = (cmd & 0xF0); //Send higher nibble 
LCD_RS = 0; // Send LOW pulse on RS pin for selecting Command register 
LCD_RW = 0; // Send LOW pulse on RW pin for Write operation
 LCD_EN = 1; // Generate a High-to-low pulse on EN pin delay(1000); 
LCD_EN = 0; 
delay(10000); 
LcdDataBus = ((cmd<<4) & 0xF0); //Send Lower nibble 
LCD_RS = 0; // Send LOW pulse on RS pin for selecting Command register 
LCD_RW = 0; // Send LOW pulse on RW pin for Write operation 
LCD_EN = 1; // Generate a High-to-low pulse on EN pin 
delay(1000); 
LCD_EN = 0; 
delay(10000); 
}


void lcd_data_string(unsigned char *str) // Function to send data to string
{
int i=0;
while(str[i]!='\0')
{
  Lcd_DataWrite(str[i]);
  i++;
  //delay(10);
}
return;
}



main()

{
	
char buffer[10];
int value = 123;
	float value1 = 12.3;
int prevcount;
	
	
Lcd_CmdWrite(0x02); // Initialize Lcd in 4-bit mode 
Lcd_CmdWrite(0x28); // enable 5x7 mode for chars 
Lcd_CmdWrite(0x0E); // Display OFF, Cursor ON 
Lcd_CmdWrite(0x01); // Clear Display Lcd_CmdWrite(0x80); // Move the cursor to beginning of first line
IT0=1;  
IE=0x81;                    
	
	Lcd_CmdWrite(0x80); // Clear Display Lcd_CmdWrite(0x80); // Move the cursor to beginning of first line
		 lcd_data_string("count=");
while(1)

{
	
	if(	prevcount!=count)
		 {
	
Lcd_CmdWrite(0xc0); // Clear Display Lcd_CmdWrite(0x80); // Move the cursor to beginning of first line
		sprintf(buffer, "%d", count);
		 lcd_data_string(buffer);
			 prevcount=count;
		 }
}


}



void extr0(void) interrupt 0     //Subroutine EX0 with interrupt number '0'
      {				
count++;				
				
      }
