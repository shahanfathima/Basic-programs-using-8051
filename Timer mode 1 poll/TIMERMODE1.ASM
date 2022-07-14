; LED BLINK WITH 1 SEC DELAY

; Find the count value for 50 ms

;n= delay / 1.085us
; n= 46083; 65356-46083=19453 =(4BFD)H

; run 20 times to get 1 s - 50ms X 20 =1000ms = 1sec

		MOV TMOD,#01H
AGAIN:	MOV R0,#10
LOOP1:	MOV TL0,#0FDH
		MOV TH0,#4BH
		SETB TR0
CHECK:	JNB TF0,CHECK
		CLR TR0		
		CLR TF0
		DJNZ R0,LOOP1
		CPL P1.0
		SJMP AGAIN
END