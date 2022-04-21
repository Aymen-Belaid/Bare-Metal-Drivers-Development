#include "stm32h723xx.h"
#include "stdint.h"
#include "stdio.h"

#include "usart.h"

char key;
int main(void){
	RCC->AHB4ENR |= (1U<<4);
	GPIOE->MODER|=(1U<<2);
	GPIOE->MODER &=~(1U<<3);

	uart_rxtx_init();

	while(1){
		key = uart_read();
		if (key =='1')
			{GPIOE->ODR |= (1U<<1);}
		else
			{GPIOE->ODR &= (1U<<1);}
}
	return 0;
}
