#define F_CPU 16000000UL

#define UP 		0x00
#define DOWN	0x01
#define RIGHT	0x02
#define LEFT	0x03

#define MOTOR_DDR	DDRC
#define MOTOR_PORT	PORTC

#define FORWARD_MODE() (MOTOR_PORT = 0x05)
#define REVERSE_MODE() (MOTOR_PORT = 0x0A)

#define MAX_PWM_SPEED	20000
#define MIN_PWM_SPEED	1000

#define FORWARD	0x04
#define REVERSE	0x05

//Comment the MCU which you're not using.
#define ATMEGA_328P
//#define ATMEGA_32A

#include <avr/io.h>
#include "pwm.h"
#include "serial.h"

void controlMotor(uint8_t status);

uint16_t channelA = 0, channelB = 0;
uint8_t channelA_status = FORWARD, channelB_status = FORWARD;

int main(void){

	setupPWM();
	initUSART();

	MOTOR_DDR = 0x0F;

	pwm(CH_A, 0, MAX_PWM_SPEED);
	pwm(CH_B, 0, MAX_PWM_SPEED);

	while(1){
		uint8_t input = getCh();

		if(input == '0')
			controlMotor(FORWARD);
		else if(input == '1')
			controlMotor(REVERSE);
	}
	
	return 0;
}

void controlMotor(uint8_t status){
	switch(status){
		case FORWARD:
			if(channelA_status == FORWARD && channelB_status == FORWARD){
				(channelA == MAX_PWM_SPEED) ? (channelA = MAX_PWM_SPEED) : (channelA += 100);
				channelB = channelA;
			}else if(channelA_status == REVERSE && channelB_status == REVERSE){
				if(channelA > MIN_PWM_SPEED){
					channelA -= 300;
					channelB = channelA;
				}else{
					FORWARD_MODE();
					channelA_status = FORWARD;
					channelB_status = FORWARD;
				}
			}
			break;
		case REVERSE:
			if(channelA_status == REVERSE && channelB_status == REVERSE){
				(channelA == MAX_PWM_SPEED) ? (channelA = MAX_PWM_SPEED) : (channelA += 100);
				channelB = channelA;
			}else if(channelA_status == FORWARD && channelB_status == FORWARD){
				if(channelA > MIN_PWM_SPEED){
					channelA -= 300;
					channelB = channelA;
				}else{
					REVERSE_MODE();
					channelA_status = REVERSE;
					channelB_status = REVERSE;
				}
			}
			break;
	}

	pwm(CH_A, channelA, MAX_PWM_SPEED);
	pwm(CH_B, channelB, MAX_PWM_SPEED);
}