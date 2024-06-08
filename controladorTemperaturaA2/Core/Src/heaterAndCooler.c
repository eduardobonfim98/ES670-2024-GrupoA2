/* ******************************************************************************* */
/* File name:        heaterAndCooler.c                                             */
/* File description: This file contains the implementation of functions            */
/*                   for controlling the PWM duty cycle of a cooler and heater     */
/*                   using timers on an STM32 microcontroller. The functions       */
/*                   allow for setting, starting, and stopping the PWM signals     */
/*                   for both the cooler and the heater.                           */
/* Author name:      Henrique Akagi, Eduardo Siqueira, and Lucas Pavarini          */
/* Creation date:    May 15, 2024                                                   */
/* Revision date:    n/a                                                           */
/* ******************************************************************************* */

#include "heaterAndCooler.h"
#include "stm32g4xx_hal.h"
#include "tim.h"

#define COOLER_TIMER TIM8
#define HEATER_TIMER TIM1

/* ************************************************ */
/* Method name:       vCoolerfanPWMDuty             */
/*                                                      */
/* Method description: Sets the PWM duty cycle for the cooler */
/*                                                      */
/* Input params:      fCoolerDuty - duty cycle for the cooler */
/*                                                      */
/* Output params:     n/a                             */
/* ************************************************ */
void vCoolerfanPWMDuty(float fCoolerDuty) {
	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, fCoolerDuty*(1000-1));
}

/* ************************************************ */
/* Method name:       vHeaterPWMDuty                */
/*                                                      */
/* Method description: Sets the PWM duty cycle for the heater */
/*                                                      */
/* Input params:      fHeaterDuty - duty cycle for the heater */
/*                                                      */
/* Output params:     n/a                             */
/* ************************************************ */
void vHeaterPWMDuty(float fHeaterDuty) {
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1,fHeaterDuty*(1000-1));
}

/* ************************************************ */
/* Method name:       vInitCooler                   */
/*                                                      */
/* Method description: Initializes the cooler        */
/*                                                      */
/* Input params:      n/a                           */
/*                                                      */
/* Output params:     n/a                           */
/* ************************************************ */
void vInitCooler(){
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
}

/* ************************************************ */
/* Method name:       vStopCooler                   */
/*                                                      */
/* Method description: Stops the cooler              */
/*                                                      */
/* Input params:      n/a                           */
/*                                                      */
/* Output params:     n/a                           */
/* ************************************************ */
void vStopCooler(){
	HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_1);
}

/* ************************************************ */
/* Method name:       vInitHeater                   */
/*                                                      */
/* Method description: Initializes the heater        */
/*                                                      */
/* Input params:      n/a                           */
/*                                                      */
/* Output params:     n/a                           */
/* ************************************************ */
void vInitHeater(){
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

/* ************************************************ */
/* Method name:       vStopHeater                   */
/*                                                      */
/* Method description: Stops the heater              */
/*                                                      */
/* Input params:      n/a                           */
/*                                                      */
/* Output params:     n/a                           */
/* ************************************************ */
void vStopHeater(){
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
}

/* ***************************************************** */
/* Method name:       setupPWM                          */
/*                                                      */
/* Method description: Simultaneously initializes       */
/*                     both the cooler and the heater   */
/*                                                      */
/* Input params:      n/a                               */
/*                                                      */
/* Output params:     n/a                               */
/* ***************************************************** */
void setupPWM() {
    vInitHeater();
    vInitCooler();
}

