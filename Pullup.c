#include <stdint.h>
#include "TM4C123.h"
void delayms(int);

void delayms(int time)
{
	int x,y;
	for (x = 0; x<time; x++)
	{
		for (y = 0; y<7900;y++){
		}
	}
}
int main()
{
	SYSCTL->RCC|=0x02400540;  //Setting system clock
  SYSCTL->RCGCGPIO |= 0x20; //Enable clock for GPIO's
	GPIOF->DIR |= 0x02;       //PF1 is output
	GPIOF->DEN |= 0x02;       //PF1 is digital function

	while(1)
		{
		GPIOF->DATA = 0x02; //Turn Red LED on
		delayms(1000);
		GPIOF->DATA = 0x00;
		delayms(1000);
	}
	
	
	return(0);
	
}

