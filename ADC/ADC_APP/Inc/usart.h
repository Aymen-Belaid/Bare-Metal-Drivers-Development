/*
 * usart.h
 *
 *  Created on: Nov 23, 2021
 *      Author: aymen
 */

#ifndef USART_H_
#define USART_H_

#include "stm32h723xx.h"
#include "stdint.h"

void uart_tx_init(void);
void uart_rxtx_init(void);
char uart_read(void);
void uart_write(uint16_t ch);
int __io_putchar (int ch);
#endif /* USART_H_ */
