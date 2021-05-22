#include <stdint.h>
#include <stdio.h>
#include <MyProject.h>


/**
 * main.c
 */
int main(void)
{
    volatile uint32_t ui32Loop;
    SYSCTL_RCGC2_R |= 0x20;
    GPIO_PORTF_DIR_R = 0xE;
    GPIO_PORTF_DEN_R = 0xE;

    while(1){

        GPIO_PORTF_DATA_R = 0x02;
        for (ui32Loop = 0; ui32Loop < 200000; ui32Loop++){
        }
        GPIO_PORTF_DATA_R = 0x04;
        for (ui32Loop = 0; ui32Loop < 200000; ui32Loop++){
        }
        GPIO_PORTF_DATA_R= 0x08;
        for (ui32Loop = 0; ui32Loop < 200000; ui32Loop++){
        }

    }
    return 0;
}


