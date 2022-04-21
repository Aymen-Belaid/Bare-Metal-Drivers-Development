#include "stm32h723xx.h"


void tim2_05HZ_init (void)
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
	}

