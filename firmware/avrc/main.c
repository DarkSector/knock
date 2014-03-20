#define F_CPU 8000000UL

#include <avr/io.h>
#include "customutils.h"
#include "serialutils.h"
#include "adcutils.h"
#include <stdio.h>

char outs[20];

int main(void){
	init_led();	
	
	USART_Init(UBBR_9600);
	USART_tx_string("Connected!\r\n");    // we're alive!
	
	adc_chan_select(ADC_CHAN_INT_TEMP);
	adc_init(ADC_VREF_EXT_CAP, ADC_PS_32, ADC_ADJ_LEFT);
	adc_enable();

	blink_led(700, 3);

	while(1){

		unsigned int adc_data = 0;
		adc_data = adc_read();
		snprintf(outs,sizeof(outs),"%3d\r\n", adc_data);  // print it
    	USART_tx_string(outs);
		
	}
	return 0;
}
