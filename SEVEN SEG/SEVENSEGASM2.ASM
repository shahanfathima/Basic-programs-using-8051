ORG 200H
TABLE:  
    DB 3FH,06H, 5BH, 4FH,66H,6DH, 7DH, 07H, 7FH, 6FH

org 00h
MAIN:
    MOV R0,#0Ah   
    MOV R2,#00H

    MOV DPTR, #TABLE 
LOOP0:
    MOV A,R2
    MOVC A, @A+DPTR        
    MOV P1,A
    ACALL DELAY       
    INC R2
    DJNZ R0,LOOP0
    SJMP MAIN

DELAY:
    MOV R3,#0FFH
LOOP2:    
    MOV    R4,#0FFH
LOOP1:
    DJNZ R4,LOOP1
    DJNZ R3,LOOP2
    RET   
    END
