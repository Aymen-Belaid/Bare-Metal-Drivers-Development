#include "stm32h723xx.h"
#include "stdint.h"
#include "stdio.h"

#include "usart.h"
#include "tim.h"


#define SR_CC3IF 	(1U<<3)

int i =0;
uint32_t ARR;
uint32_t PSC;
int x = 0;
int y = 0;

int main (void)
	{


		tim3_PB0_Toggle();
		tim2_PA1_input_capture();




		while (i<2)
		{
			while (!(TIM2->SR & SR_CC3IF)){}

			x= (int) TIM2->CCR3;
			y= y+x;
			i++;
		}
		y= (2*x -y)/25000;
}
