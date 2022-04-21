#include <stdint.h>

#define PERIPH_BASE 		(0x40000000UL)
#define AHB4_BASE 			(0x58020000UL)
#define GPIOE_OFFSET 		(0x1000UL)
#define GPIOE_BASE 			(AHB4_BASE + GPIOE_OFFSET)
#define RCC_OFFSET 			(0x4400UL)
#define RCC_BASE			(AHB4_BASE + RCC_OFFSET )

#define AHB4EN_R_OFFSET 	(0x0E0UL)
#define RCC_AHB4EN_R 		(*(volatile unsigned int *)(RCC_BASE + AHB4EN_R_OFFSET))

#define MODE_R_OFFSET 		(0x00UL)
#define GPIOE_MODE_R 		(*(volatile unsigned int *)(GPIOE_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET 		(0x14UL)
#define GPIOE_OD_R			(*(volatile unsigned int *)(GPIOE_BASE+OD_R_OFFSET))

#define PIN1				(1U<<1)
#define LED_PIN 			PIN1

#define GPIOE_EN 			(1U<<4)

#define __IO 		volatile
typedef struct
{ volatile uint32_t DUMMY[56];
  volatile uint32_t AHB4EN;
	}RCC_TypeDef;


typedef struct
	{ 	volatile uint32_t MODER;
		volatile uint32_t DUMMY[4];
		volatile uint32_t ODR;
		}GPIOE_TypeDef;

#define RCC 		((RCC_TypeDef *)RCC_BASE )
#define GPIOE 		((GPIOE_TypeDef*)GPIOE_BASE )


int main(void){
	/*RCC_AHB4EN_R |= GPIOE_EN; // Enable clock to GPIOA through the BUS
	GPIOE_MODE_R |=(1U<<2); // Set bit 2 to 1
	GPIOE_MODE_R &=~(1U<<3); // Set Bit 3 to 0 */

	RCC->AHB4EN |= GPIOE_EN;
	GPIOE->MODER|=(1U<<2);
	GPIOE->MODER&=~(1U<<3);

	while (1)
	  {//GPIOE_OD_R |=LED_PIN;
		//GPIOE_OD_R ^=PIN1;
		GPIOE->ODR^=PIN1;
		for(int i=0; i<200000; i++){}
	  }
}


