/* ******************************************************************************* */
/* File name:        tachometer.c                                                  */
/* File description: This file contains the implementation of functions            */
/*                   for initializing and updating a tachometer using              */
/*                   a timer on an STM32 microcontroller. The tachometer           */
/*                   measures the rotational speed of a cooler and calculates      */
/*                   the speed in rotations per minute.                            */
/* Author name:      Henrique Akagi, Eduardo Siqueira, and Lucas Pavarini          */
/* Creation date:    May 15, 2024                                                  */
/* Revision date:    20 of June 2024                                                              */
/* ******************************************************************************* */

#include "tim.h"
#include "main.h"
#include "tachometer.h"

float fRotations;
float fPeriod;

unsigned short int usCoolerSpeed;

unsigned int uiTachometerPeriod;
TIM_HandleTypeDef *pTimerTachometer;

/* ************************************************ */
/* Method name:       vTachometerInit               */
/*                                                      */
/* Method description: Initializes the tachometer   */
/*                                                      */
/* Input params:      htim - pointer to the tachometer timer */
/*                    uiPeriod - period of the tachometer */
/*                                                      */
/* Output params:     n/a                             */
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
/* Method name:       vTachometerUpdate             */
/*                                                      */
/* Method description: Updates the tachometer readings */
/*                                                      */
/* Input params:      n/a                           */
/*                                                      */
/* Output params:     n/a                           */
/* ************************************************ */
void vTachometerUpdate(void){
	fRotations = TIM3->CNT/9.0;
	//transform the period ms to min
	fPeriod = uiTachometerPeriod/60000.0;
	usCoolerSpeed = fRotations/fPeriod;
	TIM3->CNT = 0;
}

