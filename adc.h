/*
 * adc.h
 *
 * Created: 10/17/2015 12:48:58 PM
 *  Author: alaa
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <inttypes.h>

void Adc_Init (void);

uint16_t Adc_Read (uint8_t);

void out_temp_lcd(void);


#endif /* ADC_H_ */