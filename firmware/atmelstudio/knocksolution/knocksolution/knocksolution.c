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

char ldr_outs[20];
char piezo_outs[20];
//volatile unsigned int adc_data
unsigned int ldr_data;
unsigned int piezo_data;

int main(void)
{
	init_led();
	adc_init(ADC_AREF_EXT_CAP, ADC_PS_32, ADC_ADJ_LEFT);
	//adc_chan_select(LDR_SENSOR);
	adc_enable();
	blink_led(400, 3);
	USART_Init(UBBR);
	USART_tx_string("Connected!\n");
    while(1)
    {
		
		ldr_data = 0;
		piezo_data = 0;
		adc_chan_select(LDR_SENSOR);
		ldr_data = adc_read();
		//delay_ms(25);
		

		
		if(ldr_data <= 100){
			// Implies ambient light is off
			led_on();			
		}
		else{
			// Implies ambient light is ON
			led_off();
		}
		snprintf(ldr_outs,sizeof(ldr_outs),"%3d -", ldr_data);  // print ldr data		
		USART_tx_string(ldr_outs);
			
		adc_chan_select(PIEZO);
		piezo_data = adc_read();
		
		snprintf(piezo_outs,sizeof(piezo_outs),"%3d\n", piezo_data);  // print piezo data		
		USART_tx_string(piezo_outs);
    }
}

