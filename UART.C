#include <stdint.h>
#include "TM4C123.H"

int main()
{
char c;
//Enable module using RCGCUART register
SYSCTL->RCGCUART |= 0x01; //enable clock for UART0

//Enable clock for correct GPIO module 
SYSTCL->RCGCPIO |=0x01;

//Enable the GPIO AFSEL
SYSTCL->AFSEL(1<<1)|(1<<0);

//Enable the alternet functions	
	
GPIOA->DEN = 0x03;     //  Make PA0 and PA1 as digital
Delay(1)
GPIOA->AFSEL = 0x03;  // Use PA0,PA1 alternate function

UART0->IBRD = 104;   // setting baud rate to 9600
UART0->FBRD = 11;
UART0->CTL  = 0x301; // enable the UART0 Transmit and recieve as well as the enable registers
UART0->LCRH = 0x60; // 8-bit, no parity, 1-stop bit, no FIFO 
  
while(1){
  
  UART0_Transmitter('H');
  UART0_Transmitter('E');
  UART0_Transmitter('L');
  UART0_Transmitter('L');
  UART0_Transmitter('O');
  UART0_Transmitter('\n');
  
  
  }//while
  
}//main




void Delay(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter; i++);
}



