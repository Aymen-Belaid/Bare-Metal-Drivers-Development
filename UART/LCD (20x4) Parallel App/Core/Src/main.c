#include "stm32h723xx.h"
#include "stdint.h"
#include "stdio.h"
#include "usart.h"
#include "delay.h"

void init_lcd (void);
void affiche_lcd (char* str, int row);
void send_data_lcd (uint8_t data);
void send_cmd_lcd (uint8_t cmd);
void send_half (uint8_t half);


char key;
int i ;
int r;
int fin ;
int main (void)
{
	RCC->AHB4ENR |= (1U<<0);


	GPIOA->MODER |= (1U<<0);
	GPIOA->MODER &=~ (1U<<1);

	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER &=~ (1U<<3);

	GPIOA->MODER |= (1U<<4);
	GPIOA->MODER &=~ (1U<<5);

	GPIOA->MODER |= (1U<<6);
	GPIOA->MODER &=~ (1U<<7);

	GPIOA->MODER |= (1U<<8);
	GPIOA->MODER &=~ (1U<<9);

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~ (1U<<11);


	//uart_rxtx_init();
	init_lcd();
	affiche_lcd ("NHEB", 0);
fin =1 ;
RCC->AHB4ENR|=(1U<<1);
RCC->AHB4ENR|=(1U<<4);

GPIOE->MODER &=~(1U<<3);
GPIOB->MODER &=~(1U<<1);
GPIOB->MODER &=~(1U<<29);
while (1){
	fin = 2;
	GPIOB->ODR ^=(1U<<14);
	systickDelayMs (4000);

}

}

void init_lcd (void)
{
	systickDelayMs (100);
	GPIOA->ODR &=~ (1U << 4); // RS <- 0 (CMD)

	send_half (((0x30) >> 4) & 0x0F);
	systickDelayMs (10);

	send_half (((0x30) >> 4) & 0x0F);
	systickDelayUs (200);

	send_half(((0x30) >> 4) & 0x0F);
	systickDelayUs (200);

	send_half (((0x20) >> 4) & 0x0F);
	systickDelayUs (70);

	send_cmd_lcd (0x28);
	systickDelayUs (70);

	send_cmd_lcd (0x08);
	systickDelayUs (70);

	send_cmd_lcd (0x01);
	systickDelayMs (3);

	send_cmd_lcd (0x06);
	systickDelayUs (70);

	send_cmd_lcd (0x0C);
	systickDelayUs (70);



}

uint8_t ddram_mask = (0x80);
uint8_t cgram_mask = (0x40);
void affiche_lcd (char* str, int row)
{
	//uint8_t ddram_row ;

	/*switch (row)
	{
		case 1 :
			ddram_row = (0x00);
		case 2 :
			ddram_row = (0x40);
		case 3 :
			ddram_row = (0x14);
		case 4 :
			ddram_row = (0x54);
	}
	send_cmd_lcd (cgram_mask);
	send_cmd_lcd (ddram_row |= ddram_mask);

	systickDelayUs (40);
	uart_tx_init();*/
	while( (*str) != '\0'){

		send_data_lcd ((uint8_t)(*str));
		systickDelayUs (70);
			str++;}
}

int k=0;
uint8_t data_H = 0x00;
uint8_t data_L = 0x00;
void send_data_lcd (uint8_t data){

	GPIOA->ODR |= (1U << 4); // RS <- 1 (DATA)

		data_H = ( (data >> 4) & 0x0F );
		send_half (data_H);
	//systickDelayUs (40);
		data_L = (data & 0x0F );
		send_half (data_L);


	//systickDelayUs (40); // Delay Execution Time

	k++;
}


int j =0;
uint8_t cmd_H = 0x00;
uint8_t cmd_L = 0x00;
void send_cmd_lcd (uint8_t cmd)
{

	GPIOA->ODR &=~ (1U << 4); // RS <- 0 (CMD)
		cmd_H = ( (cmd >> 4) & 0x0F );
		send_half (cmd_H);


		cmd_L = ( cmd & 0x0F );
		send_half (cmd_L);

	//systickDelayUs (40);
	j++;

}

uint8_t half_HL;
void send_half (uint8_t half){
	half_HL	= half;
	GPIOA->ODR &=~ (0x2F); // Reinit ODR PA0 -> PA5 except RS

		if (half & (1U<<0)) {GPIOA->ODR |= (1U << 0);}
		if (half & (1U<<1)) {GPIOA->ODR |= (1U << 1);}
		if (half & (1U<<2)) {GPIOA->ODR |= (1U << 2);}
		if (half & (1U<<3)) {GPIOA->ODR |= (1U << 3);}
	GPIOA->ODR |= (1U<<5); // E <- 1
		systickDelayUs (1);
	GPIOA->ODR &=~ (1U<<5); // E <- 0
		systickDelayUs (1);

}


