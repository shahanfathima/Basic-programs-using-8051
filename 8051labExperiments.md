## BASIC PROGRAMS USING 8051


### AIM
To familiarize with 8051 and to execute some basic programs Keil IDe.

### THEORY
A Microcontroller is a powerful CPU tightly coupled with memory, various input output features such as serial port, parallel port, timer/counter interrupt controller etc. 8051 is a powerful 8 bit microcontroller on a single chip. It is optimized for control applications 64kB program memory address space of which 4 kB on chip. Major features of 8051 are:
1.8bit CPU optimized for control applications.
2. Extensive Boolean processing capabilities.
3. 64kB data and program memory addressing.
4.4kB of on chip program memory
5. On chip oscillation and clock circuitry. 

~~~
CLR C ;Clear carry flag
MOV A,#34 ;Copy 34 to A
ADD A,#78 ;Add immediate value 78 with the content of the Acc
MOV DPTR,#4100 ;Initialize memory location
MOVX @DPTR,A ;Move the contents from Acc to 
~~~
