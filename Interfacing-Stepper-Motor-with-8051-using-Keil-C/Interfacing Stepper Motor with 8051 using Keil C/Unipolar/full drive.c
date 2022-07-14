#include<reg52.h>
#include<stdio.h>
void delay(int);
void main()
{
	
//	; 39c6 clok
//;c936
	
	P2 = 0x0c; //0011
	delay(1000);
	P2 = 0x09; //0110
	delay(1000);
	P2 = 0x03; //1100
	delay(1000);
	P2 = 0x06; //1001
	delay(1000);
	while(1);

}
void delay(int k)
{
 int i,j;
 for(i=0;i<k;i++)
 {
  for(j=0;j<1000;j++)
  {}
 }
}