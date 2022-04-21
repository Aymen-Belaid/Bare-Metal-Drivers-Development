/*
 * ADC.h
 *
 *  Created on: Dec 9, 2021
 *      Author: aymen
 */

#ifndef ADC_H_
#define ADC_H_
void PA0_ADC_init (void);
void start_conversion (void);
uint32_t adc_read (void);

#endif /* ADC_H_ */
