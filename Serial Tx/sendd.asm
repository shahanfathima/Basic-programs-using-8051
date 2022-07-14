MOV TMOD, #20H ; Timer 1, mode 2
MOV TH1,#0X0FD; is loaded to set the baud rate. (0X0FD)
MOV TL1,#0X0FD; 
MOV SCON, #50H
SETB TR1 ; Run Timer 1
MOV SBUF,#44H
Loop: JNB TI, Loop ; Monitor TI
CLR TI
Loop2:SJMP Loop2
END
