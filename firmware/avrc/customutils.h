#ifndef __CUSTOMUTILS_H__
#define __CUSTOMUTILS_H__

#define LED_DD_PORT DDRB
#define LED_DD DDB0
#define LED_PORT_PIN PORTB0

#include <avr/io.h>
#include <utils/delay.h>

// Prototype
void delay_ms(unsigned int delay);
void init_led(void);
void blink_led(unsigned int delay_value, int no);

void delay_ms(unsigned int delay){
	// Custom Delay function
	int i = 0;
	for(i=0;i<delay;i++){
		// Call the AVR Delay function for 1ms
		_delay_ms(1);
	}
}

void init_led(void){
	// Declare the LED pin to the o/p
	LED_DD_PORT = (1<<LED_DD);
}

void blink_led(unsigned int delay_value, int no){
	//Blink LED {{no}} times withe {{delay_value}} delay value
	int i=0;
	for(i=0;i<no;i++){
		// Turn on
		PORTB = (0<<LED_PORT_PIN);
		delay_ms(delay_value);
		// Turn off
		PORTB = (1<<LED_PORT_PIN);
		delay_ms(delay_value);			
	}
}

#endif