/* ******************************************************************************* */
/* File name:        buzzer.c                                                      */
/* File description: This file contains the implementation of functions            */
/*                   for configuring, playing, and stopping a buzzer using         */
/*                   timers on an STM32 microcontroller. The functions             */
/*                   allow for setting the frequency and period of the buzzer,     */
/*                   as well as starting and stopping the PWM signal.              */
/* Author name:      Henrique Akagi, Eduardo Siqueira, and Lucas Pavarini          */
/* Creation date:    May 15, 2024                                                  */
/* Revision date:    20 of June 2024                                                             */
/* ******************************************************************************* */

#include "main.h"
#include "buzzer.h"
#include "tim.h"

unsigned short int usBuzzerPeriod;
unsigned short int usBuzzerFrequency;
TIM_HandleTypeDef *pTimerBuzzer;

/* ************************************************ */
/* Method name:       vBuzzerConfig                 */
/*                                                      */
/* Method description: Configures the buzzer         */
/*                                                      */
/* Input params:      usFrequency - frequency of the buzzer */
/*                    usPeriod - period of the buzzer */
/*                    htim - pointer to the buzzer timer */
/*                                                      */
/* Output params:     n/a                             */
/* ************************************************ */
void vBuzzerConfig(unsigned short int usFrequency, unsigned short int usPeriod, TIM_HandleTypeDef *htim){
	pTimerBuzzer = htim;
	usBuzzerPeriod = usPeriod;
	usBuzzerFrequency = usFrequency;
	TIM20->ARR = (uint32_t)1000000/usBuzzerFrequency - 1;
	TIM20->CCR1 = (uint32_t)(0.5*usBuzzerFrequency - 1);
	pTimerBuzzer->Instance->ARR = 10*usBuzzerPeriod - 1;
}

/* ************************************************ */
/* Method name:       vBuzzerPlay                   */
/*                                                      */
/* Method description: Starts the buzzer sound       */
/*                                                      */
/* Input params:      n/a                           */
/*                                                      */
/* Output params:     n/a                           */
/* ************************************************ */
void vBuzzerPlay(void){
	pTimerBuzzer->Instance->CNT = 0;
	HAL_TIM_PWM_Start(&htim20, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(pTimerBuzzer);
}

/* ************************************************ */
/* Method name:       vBuzzerStop                   */
/*                                                      */
/* Method description: Stops the buzzer sound        */
/*                                                      */
/* Input params:      n/a                           */
/*                                                      */
/* Output params:     n/a                           */
/* ************************************************ */
void vBuzzerStop(void){
	HAL_TIM_PWM_Stop(&htim20, TIM_CHANNEL_1);
}

