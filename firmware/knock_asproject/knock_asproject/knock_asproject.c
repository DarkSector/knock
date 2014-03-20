/*
 * knock_asproject.c
 *
 * Created: 3/8/2014 11:31:27 AM
 *  Author: DarkSector
 */ 

/*
Notes: adc_enable must be called before
the rest of the ADC parameters can be set
*/


#define F_CPU 8000000UL

#include <avr/io.h>
#include "customutils.h"
#include "serialutils.h"
#include "adcutils.h"

int main(void){
	init_led();
	
	blink_led(400, 3);
	//delay_ms(1000);
	while(1){
		blink_led(100,1);
	}
	return 0;
}




