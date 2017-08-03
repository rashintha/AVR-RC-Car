#define BAUD_RATE 9600
#define BAUD_VAL (F_CPU / (16 * BAUD_RATE) - 1)

#include <avr/io.h>
#include "cpu_def.h"

void initUSART(void);
uint8_t getCh(void);
void putCh(uint8_t data);

void initUSART(void){
   //Set Baud rate; ubrr_value = F_OSC/(16 x Baud_rate) - 1; e.g. 8e6/(9600*16) -1 =51
	UBRRL_REG = BAUD_VAL;
	UBRRH_REG = (BAUD_VAL >> 8);
	UCSRC_REG |= (1 << UCSZ1) | (1 << UCSZ0);

	#ifdef ATMEGA_32A
	UCSRC_REG |= (1 << URSEL_BIT);
	#endif

	//Enable The receiver and transmitter
	UCSRB_REG = (1 << RXEN_BIT) | (1 << TXEN_BIT);
}

uint8_t getCh(void){
	while(!(UCSRA_REG & (1 << RXC_BIT)));
	return UDR_REG;
}

void putCh(uint8_t data){
	while(!(UCSRA_REG & (1 << UDRE_BIT)));
	UDR_REG = data;
}