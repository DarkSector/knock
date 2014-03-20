/*
 * knocksolution.c
 *
 * Created: 3/19/2014 10:51:09 PM
 *  Author: DarkSector
 */ 

#define F_CPU 8000000UL
#define BAUD 9600

#include <avr/io.h>
#include "adcutils.h"
#include "customutils.h"
#include "serialutils.h"
#include <stdio.h>

#define PIEZO ADC_CHAN_ADC5
#define LDR_SENSOR ADC_CHAN_ADC4

char outs[20];
//volatile unsigned int adc_data
unsigned int adc_data;

int main(void)
{
	init_led();
	adc_init(ADC_AREF_EXT_CAP, ADC_PS_32, ADC_ADJ_LEFT);
	adc_chan_select(LDR_SENSOR);
	adc_enable();
	blink_led(400, 3);
	USART_Init(UBBR);
	USART_tx_string("Connected!\n");
    while(1)
    {

        adc_data = 0;
		adc_data = adc_read();
		snprintf(outs,sizeof(outs),"%3d\r\n", adc_data);  // print it
		
		USART_tx_string(outs);
    }
}

