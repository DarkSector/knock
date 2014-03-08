#define F_CPU 8000000UL

#include <avr/io.h>
#include "customutils.h"
// #include "serialutils.h"
#include "adcutils.h"

int main(void){
	init_led();	
	blink_led(700, 3);
	delay_ms(2000);
	while(1){		
		blink_led(700,1);
	}
	return 0;
}
