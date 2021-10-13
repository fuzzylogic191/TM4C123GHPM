#include <stdint.h>
#include "TM4C123.h"

char  readChar(void);
void  printChar(char c);
void  printString(char * string);


int main(void)
{
	
	char c;
	//Enable module using RCGCUART register
	SYSCTL->RCGCUART |= (1<<0); //enable clock for UART0

	//Enable clock for correct GPIO module 
	SYSCTL->RCGCGPIO |= (1<<0);

	//Enaccccccrfbvhinlgkitbbibtjdjble the GPIO AFSEL
	GPIOA->AFSEL = (1<<1)|(1<<0);
	
	GPIOA->PCTL= (1<<0)|(1<<4);

	
	//Enable the alternet functions	
	GPIOA->DEN = (1<<0)|(1<<1);    //  Make PA0 and PA1 as digital
	
	UART0->CTL  &= ~(1<<0); // enable the UART0 Transmit and recieve as well as the enable registers
	
	UART0->IBRD = 104;   // setting baud rate to 9600
	UART0->FBRD = 11;
	
	UART0->LCRH = (0x3<<5); // 8-bit, no parity, 1-stop bit, no FIFO 
	
	UART0->CC = 0x0; // Configure UART clock source
	
	UART0->CTL = (1<<0)| (1<<8) | (1<<9);
	
	SYSCTL->RCGCGPIO |= (1<<5);
	GPIOF->DIR =     (1<<1) | (1<<2) | (1<<3);
	GPIOF->DEN =     (1<<1) | (1<<2) | (1<<3);
	GPIOF->DATA &= ~ (1<<1) | (1<<2) | (1<<3);
	
	while (1){
		printString("Enter \"r\", \"g\", or \"b\":n\r");
		c = readChar();
		printChar(c);
		printString("\n\r");
		switch(c)
		{
			case 'r':
			GPIOF->DATA = (1<<1);
			 break;
			case 'b':
			GPIOF->DATA = (1<<2);
		   break;
			case 'g':
			GPIOF->DATA = (1<<3);
			 break;
			default:
			GPIOF->DATA &= ~((1<<1)| (1<<2) |(1<<3));
			 break;
		}
	}
}


char readChar(void){
	char c;
	while ((UART0->FR & (1<<4)) != 0);
	c = UART0->DR;
	return(c);
}

void printChar(char c){
while	((UART0->FR & (1<<5)) != 0){
	UART0->DR = c;
	}
}

void printString(char * string){
	while (*string)
	{
		printChar(*(string++));
	}
}
