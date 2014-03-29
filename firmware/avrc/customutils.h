/*
 * customutils.h
 *
 * Created: 3/19/2014 10:56:21 PM
 *  Author: DarkSector
 */ 


#ifndef __CUSTOMUTILS_H__
#define __CUSTOMUTILS_H__

#define LED_DD_PORT DDRB
#define LED_DD DDB0
#define LED_PORT_PIN PORTB0
#define LED_PORT PORTB

#include <avr/io.h>
#include <util/delay.h>

// Prototype custom delay function
void delay_ms(unsigned int delay);
// Initialize LEDs
void init_led(void);
// LED on
void led_on(void);
// LED off
void led_off(void);
// Blink LEDs with a delay of delay_value, {no} times
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

void led_on(void){
	LED_PORT &= ~(1<<LED_PORT_PIN);
}

void led_off(void){
	LED_PORT = (1<<LED_PORT_PIN);
}


void blink_led(unsigned int delay_value, int no){
	//Blink LED {{no}} times withe {{delay_value}} delay value
	int i=0;
	for(i=0;i<no;i++){
		// Turn on
		// PORTB = (0<<LED_PORT_PIN);
		led_on();
		delay_ms(delay_value);
		// Turn off
		//PORTB = (1<<LED_PORT_PIN);
		led_off();
		delay_ms(delay_value);
	}
}



#endif /* CUSTOMUTILS_H_ */