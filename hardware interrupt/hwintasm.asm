ORG 0000H
LJMP MAIN	
;
;interrupt service routine (ISR) 
;for hardware external interrupt INT1
;
		ORG 0013H
		CPL P1.1	
		RETI		
;
;main program for initialization
;
		ORG 30H
MAIN:	SETB IT1	     ;on negative edge of INT1
		MOV IE,#10000100B	
WAIT2:	SJMP WAIT2	
		END
