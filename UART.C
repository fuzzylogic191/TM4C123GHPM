#include <stdint.h>
#include "TM4C123.H"

void Delay(unsigned long counter);
char UART0_Receiver(void);
void UART0_Transmitter(char data);

int main()
{

SYSCTL->RCGCUART |= 0x01; //enable clock for UART0
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



