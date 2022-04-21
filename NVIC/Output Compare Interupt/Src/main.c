#include "stm32h723xx.h"
#include "stdint.h"
#include "stdio.h"

#include "usart.h"
#include "tim.h"




int i =0;
uint32_t ARR;
uint32_t PSC;

int main (void)
	{

		tim2_05HZ_interrupt_init();
		tim3_PB0_Toggle();


		while (1)
		{
		}
}

void TIM2_IRQHandler(void) {
								TIM2->SR &=~ (1U << 0);
								i++;

}
