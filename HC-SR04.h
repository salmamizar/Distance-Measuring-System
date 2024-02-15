 /******************************************************************************
 *
 * Module: HC_SR04
 *
 * File Name: HC_SR04.h
 *
 * Description: Header file for the HC_SR04 sensor driver
 *
 * Author: Abdalla Ibrahim Abdalla
 *
 *
 *******************************************************************************/

#ifndef HC_SR04_H_
#define HC_SR04_H_
#include "gpio.h"
#include "std_types.h"

#define ULTRASONIC_TRIGGER_PLUSE 10

#define ULTRASONIC_ECHO_PORT      PORTD_ID
#define ULTRASONIC_ECHO_PIN       PIN6_ID

#define ULTRASONIC_TRIGGER_PORT   PORTB_ID
#define ULTRASONIC_TRIGGER_PIN    PIN5_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);


#endif /* HC_SR04_H_ */
