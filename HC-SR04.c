/******************************************************************************
 *
 * Module: HC_SR04
 *
 * File Name: HC_SR04.c
 *
 * Description: Source file for the HC_SR04 sensor driver
 *
 * Author: Abdalla Ibrahim Abdalla
 *
 *
 *******************************************************************************/
#include "HC-SR04.h"
#include "icu.h"
#include "std_types.h"
#include "util/delay.h"


static uint16 high_time=0;
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void Ultrasonic_init(void)
{
	/*Initializing the icu driver*/
	ICU_ConfigType myType ={F_CPU_8,RAISING};
	ICU_init(&myType);

	/*setting the call back function at icu driver*/
	ICU_setCallBack(Ultrasonic_edgeProcessing);

	/* setting the direction for the trigger pin as output pin using gpio driver*/
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, PIN_OUTPUT);



}

void Ultrasonic_Trigger()
{
	/*at this function we need to give the trigger pin a pulse for at least 10 us*/
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOGIC_HIGH);
	_delay_us(ULTRASONIC_TRIGGER_PLUSE);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOGIC_LOW);

}

uint16 Ultrasonic_readDistance(void)
{
	uint16 distance ;
	/*starting the sensor trigger*/
	Ultrasonic_Trigger();

	distance=((float)high_time)/58.8;
	return ((distance));

}

void Ultrasonic_edgeProcessing()
{
	static uint8 numOfEdges=0;
	numOfEdges++;
	if(numOfEdges == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING );
	}
	else if(numOfEdges == 2)
	{
		/* Store the High time value */
		high_time = ICU_getInputCaptureValue();

		numOfEdges=0;
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);

	}


}
