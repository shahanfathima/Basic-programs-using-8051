		;1428
		
		org 0H
		stepper equ P1
main:
		mov stepper, #8H
		acall delay
		mov stepper, #2H
		acall delay
		mov stepper, #4H
		acall delay
		mov stepper, #1H
		acall delay
		jmp main


	

delay: 	
		MOV r0,0ffH
loop4:		
		mov r1,0ffh
loop3:		
		djnz r1,loop3
		djnz r0,loop4
		ret
		END
