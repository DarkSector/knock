// Author: Pronoy Chopra (DarkSector)
#ifndef __ADCUTILS_H__
#define __ADCUTILS_H__

#include <avr/io.h>
#define adc_converion_ongoing (ADCSRA & (1<<ADSC))

// void adc_init(adc_ref_t ref, adc_ps_t ps, adc_adj_t adj);
unsigned int adc_read(void);
void adc_enable();
// void adc_chan_select(adc_chan_t chan);
void adc_conversion_start(void);


typedef enum {
	ADC_AREF_INTERNAL = ((0<<REFS1)|(0<<REFS0)),
	ADC_AREF_EXT_CAP = ((0<<REFS1)|(1<<REFS0))
	ADC_RESERVED = ((1<<REFS1)|(0<<REFS0)),
	ADC_INT_VREF = ((1<<REFS1)|(1<<REFS0)),
} adc_ref_t;

typedef enum {
    ADC_PS_2   = ((0<<ADPS2)|(0<<ADPS1)|(1<<ADPS0)),
    ADC_PS_4   = ((0<<ADPS2)|(1<<ADPS1)|(0<<ADPS0)),
    ADC_PS_8   = ((0<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)),
    ADC_PS_16  = ((1<<ADPS2)|(0<<ADPS1)|(0<<ADPS0)),
    ADC_PS_32  = ((1<<ADPS2)|(0<<ADPS1)|(1<<ADPS0)),
    ADC_PS_64  = ((1<<ADPS2)|(1<<ADPS1)|(0<<ADPS0)),
    ADC_PS_128 = ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0))
} adc_ps_t;
	
typedef enum {
	ADC_CHAN_ADC0 = ((0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0)),
	ADC_CHAN_ADC1 = ((0<<MUX3)|(0<<MUX2)|(0<<MUX1)|(1<<MUX0)),
	ADC_CHAN_ADC2 = ((0<<MUX3)|(0<<MUX2)|(1<<MUX1)|(0<<MUX0)),
	ADC_CHAN_ADC3 = ((0<<MUX3)|(0<<MUX2)|(1<<MUX1)|(1<<MUX0)),
	ADC_CHAN_ADC4 = ((0<<MUX3)|(1<<MUX2)|(0<<MUX1)|(0<<MUX0)),
	ADC_CHAN_ADC5 = ((0<<MUX3)|(1<<MUX2)|(0<<MUX1)|(1<<MUX0)),
	ADC_CHAN_ADC6 = ((0<<MUX3)|(1<<MUX2)|(1<<MUX1)|(0<<MUX0)),
	ADC_CHAN_ADC7 = ((0<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0)),
	ADC_CHAN_INT_TEMP = ((1<<MUX3)|(0<<MUX2)|(0<<MUX1)|(0<<MUX0))
} adc_chan_t;

typedef enum {
	ADC_ADJ_RIGHT = 1,
	ADC_ADJ_LEFT = 0
} adc_adj_t;


void adc_init(adc_ref_t ref, adc_ps_t ps, adc_adj_t adj){
	ADMUX |= ref|adj;
	ADCSRA |= ps;
}

void adc_chan_select(adc_chan_t chan){
	ADMUX |= chan;
}

void adc_enable(void){
	ADCSRA |= (1<<ADEN);
}

void adc_disable(void){
	ADCSRA &= ~((1<<ADEN));
}

void adc_conversion_start(void){
	ADCSRA = (1<<ADSC);
}


unsigned int adc_read(void)
{
   unsigned char i = 4;
   unsigned int adc_temp = 0;
   while (i--)
   {
      adc_conversion_start();
      // while(ADCSRA & (1<<ADSC));
      while(adc_converion_ongoing);
      adc_temp+= ADC;
      _delay_ms(50);
   }
   adc_temp = adc_temp / 4;  // Average a few samples
   return adc_temp;

}


#endif