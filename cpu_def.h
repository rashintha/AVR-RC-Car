#ifdef ATMEGA_328P
	
#define UBRRL_REG 	UBRR0L
#define UBRRH_REG 	UBRR0H
#define UCSRA_REG 	UCSR0A
#define UCSRB_REG 	UCSR0B
#define UCSRC_REG 	UCSR0C
#define UDR_REG		UDR0

#define UCSZ0_BIT 	UCSZ00
#define UCSZ1_BIT 	UCSZ01
#define RXEN_BIT  	RXEN0
#define TXEN_BIT  	TXEN0
#define RXC_BIT		RXC0
#define UDRE_BIT	UDRE0

#elif ATMEGA_32A
	
#define UBRRL_REG 	UBRRL
#define UBRRH_REG 	UBRRH
#define UCSRA_REG 	UCSRA
#define UCSRB_REG 	UCSRB
#define UCSRC_REG 	UCSRC
#define UDR_REG		UDR

#define URSEL_BIT 	URSEL
#define UCSZ0_BIT 	UCSZ0
#define UCSZ1_BIT 	UCSZ1
#define RXEN_BIT  	RXEN
#define TXEN_BIT  	TXEN
#define RXC_BIT		RXC
#define UDRE_BIT	UDRE

#endif