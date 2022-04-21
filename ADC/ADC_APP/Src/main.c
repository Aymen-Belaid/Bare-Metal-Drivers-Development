#include "stm32h723xx.h"
#include "stdint.h"
#include "stdio.h"

#include "usart.h"
#include "ADC.h"

uint32_t sensor_val;
int i ;

int main(void){

	uart_tx_init();
	PA0_ADC_init ();
	start_conversion ();
	i=1;
	while (1)
		{ sensor_val = adc_read ();
			i=2;
		  __io_putchar ((int) 'B');
		}

	return 0;
}
