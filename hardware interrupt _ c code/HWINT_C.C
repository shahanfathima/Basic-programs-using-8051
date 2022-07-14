    #include<regx52.h>
    
	
	void main()
      {
				 P1_1=0;  
	  IT0=1;
	  

       IE=0x81;                    // Activating and EX0
       while(1);
      }
  

void extr0(void) interrupt 0     //Subroutine EX0 with interrupt number '0'
      {				
P1_1=~P1_1;					
				
      }
   
  