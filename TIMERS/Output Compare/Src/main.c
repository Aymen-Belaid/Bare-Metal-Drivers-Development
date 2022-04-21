#include "stm32h723xx.h"
#include "stdint.h"
#include "stdio.h"

#include "usart.h"
#include "tim.h"



int OUT=0;
int i =0;
uint32_t ARR;
uint32_t PSC;

int main (void)
	{


		tim3_PB0_Toggle();


		while (1)
		{
			OUT= GPIOB->ODR;
		}
}
