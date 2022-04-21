#include "exti.h"

#define GPIOC_EN 			(1U<<2)
void pushb_exti_init (void){

	/*Disable global interupt*/
	__disable_irq();

	/*Enable clock access to GPIOC*/
	RCC->AHB4ENR|=GPIOC_EN;

	/*Set PC13 as input*/
	GPIOC->MODER &=~(1U<<26);
	GPIOC->MODER &=~(1U<<27);

	/*Enable clock access to SYSCONFG*/
	RCC->APB4ENR |= (1U << 1);

	/*Set PORTC for EXTI13*/
	SYSCFG->EXTICR[3] &=~ (1U << 4);
	SYSCFG->EXTICR[3] |= (1U << 5);
	SYSCFG->EXTICR[3] &=~ (1U << 6);
	SYSCFG->EXTICR[3] &=~ (1U << 7);

	/*Unmask EXTI13*/
	EXTI->IMR1 |= (1U << 13);

	/*Select falling edge trigger*/
	EXTI ->FTSR1 = (1U << 13);
	/*Enable EXTI13 line in NVIC*/
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	/*Enable global interrupts*/
	__enable_irq();

}

