/* File name:        led.c                                                 */
/* File description: File for configuring the LED registers                */
/* Author name:      Henrique Akagi, Eduardo Siqueira, and Lucas Pavarini  */
/* Creation date:    March 28, 2024                                        */
/* Revision date:    20 of June 2024                                           */
/* ************************************************************************ */

#include "led.h"
#include "main.h"


// **************************************************** //
// Method name:         vLedInitLed                     //
// Method description:  Function that initializes the   //
//                      registers, enabling the clock   //
//                      and configuring the pins        //
//                                                      //
// Input params:        n/a                             //
// Output params:       n/a                             //
// **************************************************** //
void vLedInitLed ()
{
	//inicializa o clock de A e B
	RCC->AHB2ENR |= 0x00000003;

	//coloca os pinos 4, 5 e 12 em modo de ouput
	GPIOA->MODER |= 0x01000500;
	GPIOA->MODER &= ~(0x02000A00);

	//coloca os pinos 5 e 14 em modo de ouput
	GPIOB->MODER |= 0x10000400;
	GPIOB->MODER &= ~(0x20000800);

	//os outros modos consideramos que são inicializados em reset

}

// ***************************************************** //
// Method name:         vLedWriteLed                     //
// Method description:  Function that writes the state   //
//                      of the LED                       //
// Input params:        cLedNum:                         //
//                      indicates which LED will be set  //
//                      iLedWrite:                       //
//                      indicates whether the LED will   //
//                      be set to high or low            //
// Output params:       n/a                              //
// ***************************************************** //
void vLedWriteLed (char cLedNum, int iLedWrite)
 {
	if (iLedWrite == 1)
	{
		vLedOnLed(cLedNum);
	}
	else if (iLedWrite == 0)
	{
		vLedOffLed(cLedNum);
	}
}

// ***************************************************** //
// Method name:         vLedOnLed                        //
// Method description:  Function that turns on the LED   //
// Input params:        cLedNum:                         //
//                      indicates which LED will be set  //
// Output params:       n/a                              //
// ***************************************************** //
void vLedOnLed (char cLedNum){
	switch(cLedNum){
		case green1:
			GPIOA->ODR 	|= GPIO_PIN_5;
			break;
		case yellow:
			GPIOA->ODR 	|= GPIO_PIN_4;
			break;
		case red:
			GPIOB->ODR |= GPIO_PIN_14;
			break;
		case green2:
			GPIOA->ODR 	|= GPIO_PIN_12;
			break;
		case blue:
			GPIOB->ODR  |= GPIO_PIN_5;
			break;
	}
}

// ***************************************************** //
// Method name:         vLedOffLed                       //
// Method description:  Function that turns off the LED  //
// Input params:        cLedNum:                         //
//                      indicates which LED will be set  //
// Output params:       n/a                              //
// ***************************************************** //
void vLedOffLed (char cLedNum)
{

	// write 0 on the pin of the ODR register that makes the led turn of
	switch(cLedNum)
	{
		case green1:
			BIT_CLEAR(GPIOA->ODR, 5);
			break;
		case yellow:
			BIT_CLEAR(GPIOA->ODR, 4);
			break;
		case red:
			BIT_CLEAR(GPIOB->ODR, 14);
			break;
		case green2:
			BIT_CLEAR(GPIOA->ODR, 12);
			break;
		case blue:
			BIT_CLEAR(GPIOB->ODR, 5);
			break;
	}
}

// ******************************************************** //
// Method name:         vLedToggleLed                       //
// Method description:  Function that toggles the state of  //
//                      the LED                             //
// Input params:        cLedNum:                            //
//                      indicates which LED will be set     //
// Output params:       n/a                                 //
// ******************************************************** //
void vLedToggleLed (char cLedNum)
{

	switch (cLedNum)
	{
		case green1:
			BIT_FLIP(GPIOA->ODR, 5);
			break;
		case yellow:
			BIT_FLIP(GPIOA->ODR, 4);
			break;
		case red:
			BIT_FLIP(GPIOB->ODR, 14);
			break;
		case green2:
			BIT_FLIP(GPIOA->ODR, 12);
			break;
		case blue:
			BIT_FLIP(GPIOB->ODR, 5);
			break;
	}

}

// ******************************************************** //
// Method name:         vLedShowNumber                      //
// Method description:  Function that displays a number     //
//                      using the LEDs                      //
// Input params:        int number:                         //
//                      the number to be displayed          //
// Output params:       n/a                                 //
// ******************************************************** //
void vLedShowNumber(int number) {
    // Set each LED based on the corresponding bit in 'number'
    vLedWriteLed(green1, number & 0x01); // bit 0
    vLedWriteLed(yellow, (number >> 1) & 0x01); // bit 1
    vLedWriteLed(red, (number >> 2) & 0x01); // bit 2
    vLedWriteLed(green2, (number >> 3) & 0x01); // bit 3
    vLedWriteLed(blue, (number >> 4) & 0x01); // bit 4
}
