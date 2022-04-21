/*
 * usart.c
 *
 *  Created on: Nov 23, 2021
 *      Author: aymen
 */
#include "usart.h"

#define GPIOD_EN		(1U<<3)
#define SC				62500000
#define BaudRtSys		9600
#define TXE_SetR		(1U<<7)

static void uart_set_br (USART_TypeDef *USARTn,uint32_t PClock, uint32_t BRt);
static uint16_t compute_uart_div( uint32_t PeriphClock, uint32_t BaudRt);

void uart_write(uint16_t ch);
int __io_putchar (int ch);
uint32_t BR_Val;

int __io_putchar (int ch)
{
	uart_write((uint16_t) ch);
	return (ch);
}

void uart_write(uint16_t ch)
{
	/*Make sure the transmit data register is empty */
	while (!(USART3->ISR & TXE_SetR)){}

	/*Write to transmit data register*/
	USART3->TDR = (ch);
}

void uart_rxtx_init(void)
{
/**********Configure uart gpio pin************/
	/*Enable Clock access to GPIOD*/
	RCC->AHB4ENR |= GPIOD_EN;
	/*Set PD8 to AF MODE*/
	GPIOD->MODER |= (1U<<17);
	GPIOD->MODER &=~ (1U<<16);
	/*Set PD8 AF Type to UART_TX(AF7)*/
	GPIOD->AFR[1] |= (1U<<0);
	GPIOD->AFR[1] |= (1U<<1);
	GPIOD->AFR[1] |= (1U<<2);
	GPIOD->AFR[1] &=~ (1U<<3);
	/*Set PD9 to AF MODE*/
	GPIOD->MODER |= (1U<<19);
	GPIOD->MODER &=~ (1U<<18);
	/*Set PD9 AF Type to UART_TX(AF7)*/
	GPIOD->AFR[1] |= (1U<<4);
	GPIOD->AFR[1] |= (1U<<5);
	GPIOD->AFR[1] |= (1U<<6);
	GPIOD->AFR[1] &=~ (1U<<7);

/*************Configure UART Module**********/
	/*Enable Clock access to UART3*/
	RCC->APB1LENR |= (1U<<18);
	/*Configure Baudrate*/
	uart_set_br (USART3,SC,BaudRtSys);
	//USART3->BRR= SC / BaudRtSys;
	/*Configure transfer direction*/
	USART3->CR1 = (1U<<3 | 1U<<2);
	/*Enable UART Module*/
	USART3->CR1 |= (1U<<0);
}
char uart_read(void) {
	while (!(USART3->ISR & (1U<<5))){}


		return ( (char)(USART3->RDR) );
}

void uart_tx_init(void)
{
/**********Configure uart gpio pin************/
	/*Enable Clock access to GPIOD*/
	RCC->AHB4ENR |= GPIOD_EN;
	/*Set PD8 to AF MODE*/
	GPIOD->MODER |= (1U<<17);
	GPIOD->MODER &=~ (1U<<16);
	/*Set PD8 AF Type to UART_TX(AF7)*/
	GPIOD->AFR[1] |= (1U<<0);
	GPIOD->AFR[1] |= (1U<<1);
	GPIOD->AFR[1] |= (1U<<2);
	GPIOD->AFR[1] &=~ (1U<<3);

/*************Configure UART Module**********/
	/*Enable Clock access to UART3*/
	RCC->APB1LENR |= (1U<<18);
	/*Configure Baudrate*/
	uart_set_br (USART3,SC,BaudRtSys);
	//USART3->BRR= SC / BaudRtSys;
	/*Configure transfer direction*/
	USART3->CR1 = (1U<<3);
	/*Enable UART Module*/
	USART3->CR1 |= (1U<<0);
}

static void uart_set_br (USART_TypeDef *USARTn,uint32_t PClock, uint32_t BRt)
{
	USARTn->BRR = compute_uart_div(PClock,BRt);
	}
static uint16_t compute_uart_div( uint32_t PeriphClock, uint32_t BaudRt)
{
	BR_Val = (PeriphClock + (BaudRt / 2U)) / BaudRt;
	return((uint16_t) BR_Val);
}
