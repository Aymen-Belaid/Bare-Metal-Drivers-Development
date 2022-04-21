#include "stm32h723xx.h"


void tim2_05HZ_interrupt_init (void)
	{
		/*Enable clock access to tim2 */
		RCC->APB1LENR |= (1U << 0);

		/*Clear Counter*/
		TIM2->CNT = 0;
		/*Set auto-reload value*/
		TIM2->ARR = (uint16_t) 39999;
		/*Set prescaler value*/
		TIM2->PSC = (uint16_t) 6249;
		/*Set auto-reload value*/
		TIM2->ARR = (uint16_t) 39999;

		/*Enable Timer*/
		TIM2->CR1 |= (1U << 0);

		/*Enable TIM interrupt*/
		TIM2->DIER |= (1U << 0);
		/*Enable TIM interrupt in NVIC*/
		NVIC_EnableIRQ(TIM2_IRQn);
	}

void tim3_PB0_Toggle (void)
	{

		/*Enable clock access to PB0 */
		RCC->AHB4ENR|= (1U << 1);

		/*Set PB0 mode to alternate function mode*/
		GPIOB->MODER |= (1U << 1);
		GPIOB->MODER &=~ (1U << 0);

		/*Set Alternate function type to AF2 */
		GPIOB->AFR[0] |= (1U << 1);
		GPIOB->AFR[0] &=~ (1U << 0);
		GPIOB->AFR[0] &=~ (1U << 2);
		GPIOB->AFR[0] &=~ (1U << 3);

		/*Enable clock access to tim3 */
		RCC->APB1LENR |= (1U << 1);

		/*Set auto-reload value*/
		TIM3->ARR = (uint16_t) 39999;
		/*Set prescaler value*/
		TIM3->PSC = (uint16_t) 6249;
		/*Set auto-reload value*/
		TIM3->ARR = (uint16_t) 39999;

		/*Set Output Compare toggle mode*/
		TIM3->CCMR2 |= (1U << 4) | (1U << 5);
		//TIM3->CCMR2 &=~ (1U << 6) | (1U << 16);

		/*Enable tim3 ch1 in compare mode*/
		TIM3->CCER |= (1U << 8);

		/*Clear Counter*/
		TIM3->CNT = 0;

		/*Enable Timer*/
		TIM3->CR1 |= (1U << 0);
	}
