#include "stm32h723xx.h"
#include "delay.h"
#define GPIOE_EN 			(1U<<4)
#define GPIOB_EN 			(1U<<1)
#define PIN1				(1U<<1)
#define LED_PIN 			PIN1
#define PIN0_G				(1U<<0)
#define PIN3_R				(1U<<14)

#define LED_PIN_G 			PIN0_G
#define LED_PIN_R 			PIN3_R

int main (void){
RCC->AHB4ENR|=GPIOB_EN;
RCC->AHB4ENR|=GPIOE_EN;

GPIOE->MODER &=~(1U<<3);
GPIOB->MODER &=~(1U<<1);
GPIOB->MODER &=~(1U<<29);
while (1){
	GPIOB->ODR ^=(1U<<14);
	systickDelayMs (4000);

}
}
