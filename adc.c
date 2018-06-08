/*
 * adc.c
 *
 * Created: 10/17/2015 12:48:47 PM
 *  Author: alaa
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "STDTypes.h"
#include "adc.h"
#include "LCD.h"
void Adc_Init (void) {
	ADMUX = (1<<REFS0);	// Reference Voltage AVCC
	// Enable ADC with pre-scaler 64
	ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);
}

uint16_t Adc_Read (uint8_t chan) {
	uint16_t data;
	// Select the channel
	ADMUX |= (chan & 0x07);
	// Start single conversion
	ADCSRA |= (1<<ADSC);
	// Wait for conversion to complete
	while (ADCSRA & (1<<ADSC))
		;
	// return the conversion result
	data = ADC;
	return data;
}

void out_temp_lcd(void)
{
	u16 x=0;
	LCD_Init();
	Adc_Init();
	x=Adc_Read(0);
	if( ((x/2)%10) ==0)
	{
		x=x/2;
	}
	else
	{
		x=x/2;
		x--;
	}
	LCD_OutString("The Temperature is :  ");
	LCD_OutUDec(x);
}