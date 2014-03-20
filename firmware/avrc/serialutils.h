#ifndef __SERIALUTILS_H__
#define __SERIALUTILS_H__

#define BAUD 9600UL
#define UBBR_9600 ((F_CPU/16/BAUD) - 1)

#include <avr/io.h>
#include "customutils.h"

void USART_Init(unsigned int ubrr);
void USART_tx_string(char *data);

void USART_Init( unsigned int ubrr) {
/*Set baud rate */
UCSR0A |= (1 << U2X0);
UBRR0H = (unsigned char)(ubrr>>8); 
UBRR0L = (unsigned char)ubrr;
/* Enable receiver and transmitter */ 
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 1stop bit */ 
UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
}

void USART_tx_string( char *data )
{ 
   while ((*data != '\0'))
   {
      while (!(UCSR0A & (1 <<UDRE0)));
      UDR0 = *data;
      data++;
   }  
}


#endif