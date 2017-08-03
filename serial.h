#define BAUD_RATE 9600
#define BAUD_VAL (F_CPU/(16*BAUD_RATE)-1)

#include <avr/io.h>

void initUSART(void);
uint8_t getCh(void);
void putCh(uint8_t data);

void initUSART(void){
   //Set Baud rate; ubrr_value = F_OSC/(16 x Baud_rate) - 1; e.g. 8e6/(9600*16) -1 =51
	uint32_t ubrr_value;
	ubrr_value = F_CPU/16/BAUD_RATE -1; 
	UBRRL = ubrr_value;
	UBRRH = (ubrr_value>>8);
	UCSRC=(1<<URSEL)|(3<<UCSZ0);
	//Enable The receiver and transmitter
	UCSRB=(1<<RXEN)|(1<<TXEN);
}

uint8_t getCh(void){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void putCh(uint8_t data){
	while(!(UCSRA & (1<<UDRE)));
	UDR=data;
}