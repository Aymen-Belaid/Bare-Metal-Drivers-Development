#include "stm32h723xx.h"
#include "exti.h"
#include "stdint.h"
#include "stdio.h"

#define GPIOB_EN 			(1U<<1)
int i = 0;


int main (void){
//Enabling Clock
RCC->AHB4ENR|=GPIOB_EN;

//Set Leds as outputs
GPIOB->MODER &=~(1U<<29);
GPIOB->MODER |=(1U<<28);

pushb_exti_init ();


while (1){
			GPIOB->ODR |= (1U << 14);
			}
}

void EXTI15_10_IRQHandler (void){
	if ((EXTI->PR1 & (1U << 13)) != 0)
		{	EXTI->PR1 |= (1U << 13);
			GPIOB->ODR &=~ (1U << 14);
			i++;
	    }

}

