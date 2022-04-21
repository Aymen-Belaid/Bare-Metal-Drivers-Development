#include "stm32h723xx.h"

#define SYSTICK_LOAD_VAL 		67500 //Number of clock cycles per ms
#define SYSTICK_LOAD_VAL_us 		68 //Number of clock cycles per us


void systickDelayMs (int delay){
	//Reload with nuble of clock cycles per ms
	SysTick->LOAD = (uint32_t) SYSTICK_LOAD_VAL;
	//Clear SysTick current value register
	SysTick->VAL = 0;
	//Enable Systick and select internal Clk source
	SysTick->CTRL = ((1U<<0) | (1U<<2));

	for (int i= 0 ; i< delay ; i++)
	{
		//Wait until the counterflag is set
		while ( !((SysTick->CTRL) & (1U << 16))){}

	}
SysTick->CTRL = 0;

}

void systickDelayUs (int delay_us){
	//Reload with nuble of clock cycles per ms
	SysTick->LOAD = (uint32_t) SYSTICK_LOAD_VAL_us;
	//Clear SysTick current value register
	SysTick->VAL = 0;
	//Enable Systick and select internal Clk source
	SysTick->CTRL = ((1U<<0) | (1U<<2));

	for (int i= 0 ; i< delay_us ; i++)
	{
		//Wait until the counterflag is set
		while ( !((SysTick->CTRL) & (1U << 16))){}

	}
SysTick->CTRL = 0;

}
