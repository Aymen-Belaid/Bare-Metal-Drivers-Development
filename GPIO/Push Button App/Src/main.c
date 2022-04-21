#include "stm32h723xx.h"



#define GPIOB_EN 			(1U<<1)
#define GPIOC_EN 			(1U<<2)

#define PushB				(1U<<13) // equivalent à un nbre binaire sur 32 bit avec 1 sur la pos 13
#define Button				PushB
int out = 0;
int main (void){
//Enabling Clock
RCC->AHB4ENR|=GPIOB_EN;
RCC->AHB4ENR|=GPIOC_EN;
//Set Leds as outputs
GPIOB->MODER &=~(1U<<29);

//Setting push button as input
GPIOC->MODER &=~(1U<<26);
GPIOC->MODER &=~(1U<<27);

while (1){
  if((GPIOC->IDR) & Button)
	{GPIOB->BSRR =(1U<<14);}

  else
  {GPIOB->BSRR=(1U<<30);}
out = GPIOB->ODR;
}
}
