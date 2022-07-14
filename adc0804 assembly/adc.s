        	rdbar equ P1.1           ;Read signal P1.0
        	wrbar equ P1.2           ;Write signal P1.1
        	
        	intr equ P1.3         ;INTR signal P1.3
         
        	adc_port equ P2       ;ADC data pins P2
        	adc_val equ 30H       ;ADC read value stored here
			output equ P3
         
        	org 0H
			mov adc_port,#0FFH	
			mov output,#00
start:                    ;Start of Program
        	acall conv            ;Start ADC conversion        	
        	sjmp start            ;Do it again         
conv:                     ;Start of Conversion
			setb rdbar
			clr wrbar                ;Make WR Low
			nop
			setb wrbar         
wait:
			jb intr,wait          ;Wait for INTR signal      	
			clr rdbar                ;Make RD Low
			mov output,adc_port
			nop
			setb intr
		end                  ;Reading done
			
			
