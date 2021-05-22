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

}

    }
    return 0;
}


