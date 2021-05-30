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
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0xff;
    GPIO_PORTF_PUR_R = 0x11;
    GPIO_PORTF_DIR_R = 0xE;
    GPIO_PORTF_DEN_R = 0x1F;

    while(1){

        switch (GPIO_PORTF_DATA_R & 0x11)
        {
        case 0x00:
            GPIO_PORTF_DATA_R = (1<<1);
            break;
        case 0x01:
            GPIO_PORTF_DATA_R = (1<<2);
            break;
        case 0x10:
            GPIO_PORTF_DATA_R = (1<<3);
            break;
        default:
            GPIO_PORTF_DATA_R &= !((1<<1)|(1<<2)|(1<<3));

        }

       }


    return 0;
}


