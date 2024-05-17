/*
 * tachometer.c
 *
 *  Created on: May 15, 2024
 *      Author: akira
 */

#include "tim.h"
#include "main.h"
#include "tachometer.h"

float fRotations;
float fPeriod;

unsigned short int usCoolerSpeed;

unsigned int uiTachometerPeriod;
TIM_HandleTypeDef *pTimerTachometer;

/* ************************************************ */
/* Method name: 	   vTachometerInit      		*/
/*													*/
/* Method description: inicializa o tacometro   	*/
/*													*/
/* Input params:	   timer do tacometro e periodo
 * 						do tacometro				*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vTachometerInit(TIM_HandleTypeDef *htim, unsigned int uiPeriod){
	pTimerTachometer = htim;
	uiTachometerPeriod = uiPeriod;
	__HAL_TIM_SET_AUTORELOAD(htim, 10*uiTachometerPeriod - 1);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_IC_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(pTimerTachometer);
}

/* ************************************************ */
/* Method name: 	   vTachometerUpdate      	*/
/*													*/
/* Method description: update do tacometro   		*/
/*													*/
/* Input params:	    n/a 						*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vTachometerUpdate(void){
	fRotations = TIM3->CNT/9.0;
	//transform the period ms to min
	fPeriod = uiTachometerPeriod/60000.0;
	usCoolerSpeed = fRotations/fPeriod;
	TIM3->CNT = 0;
}

