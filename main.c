/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: main program for mini project 4
 *
 * Author: Abdalla Ibrahim Abdalla
 *
 *******************************************************************************/
#include "avr/io.h"
#include "lcd.h"
#include "HC-SR04.h"
#include "avr/delay.h"
int main(void)
{

	/*enabling interrupt*/
	SREG|=(1<<7);
	LCD_init();
	Ultrasonic_init();
	LCD_displayString(" DISTANCE =   CM");
	uint16 distance=0;
	while(1)
	{
		distance =Ultrasonic_readDistance();
		LCD_moveCursor(0,11);
		LCD_intgerToString (distance);
		 if (distance<100)
		 {
			 LCD_displayCharacter(' ') ;
		 }
		 _delay_ms(100);
	}

}
