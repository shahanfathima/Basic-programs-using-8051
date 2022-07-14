#include<reg52.h>
#include<stdio.h>

void delay(int);

void main()
	
{
 int l;
	while(1)
	{
	
	for(l=0;l<4;l++)
	{
   P2=0x01; //0001
   delay(1000);
   P2=0x04; //0100
   delay(1000);
   P2=0x02; //0010
   delay(1000);
   P2=0x08; //1000
   delay(1000);

}
	while(1);
	}
}

void delay(int k)
{
 int i,j;
 for(i=0;i<k;i++)
 {
  for(j=0;j<10;j++)
  {}
 }
}