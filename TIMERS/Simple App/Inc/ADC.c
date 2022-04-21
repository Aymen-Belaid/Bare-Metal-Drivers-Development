#include "stm32h723xx.h"
#include "ADC.h"

#define ADC_EN 			(1U << 5)
#define GPIOA_EN 		(1U << 0)
#define ADC_CH16		(1U << 10)
#define CR1_ADEN		(1U << 0)
#define CR1_ADSTART		(1U << 2)
#define ISR_EOC 		(1U << 2)

void PA0_ADC_init (void){

	/*** Config ADC pin***/
	/*Enable clock access to GPIOA*/
	RCC->AHB4ENR |= GPIOA_EN;
	/*Set the mode of PA0 to Analog Mode */
	GPIOA->MODER |= (1U << 0);
	GPIOA->MODER |= (1U << 1);
	/*** Configure ADC Module ***/
	/*Enable clock access to ADC Module*/
	RCC->AHB1ENR |= ADC_EN;
	//Conversion sequence start
	ADC1->SQR1 = ADC_CH16;
	//Conversion sequence length
	//1 conv <=> 0000 in L (In SQR1)
	//Enable the ADC module
	ADC1->CR |= CR1_ADEN;


}

void start_conversion (void){

	//ADC1->CR &=~ CR1_ADSTART;

	//ADC1->CFGR &=~ (1U << 16);

	/* configure CONT Bit*/
	ADC1->CFGR |= (1U << 13);
	/*ADC1 ->CFGR &=~ (1U << 10);
	ADC1 ->CFGR &=~ (1U << 11);*/

	// while (ADC1->CR & (1U << 1)){}
	ADC1->CR |= CR1_ADSTART;

}
uint32_t CR ;
uint32_t ISR ;
uint32_t adc_read (void)
{	CR = (ADC1->CR );
	ISR= (ADC1->ISR);
	/*Wait for conversion to be complete*/
	while (! (ADC1->ISR & ISR_EOC )) {}
	/*Read covered result*/
	return (ADC1->DR);
	ADC1->ISR &=~ ISR_EOC;
}

