#include "stm32h723xx.h"
#include "stdint.h"
#include "stdio.h"

#include "usart.h"

char key;
int main(void){

	uart_rxtx_init();

	while(1){
				key = uart_read();
				uart_write((uint16_t) key);
			}
	return 0;
}
