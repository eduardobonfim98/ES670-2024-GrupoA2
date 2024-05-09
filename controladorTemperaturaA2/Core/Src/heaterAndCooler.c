/*
 * heaterAndCooler.c
 *
 *  Created on: May 9, 2024
 *      Author: akira
 */

#include "heaterAndCooler.h"
#include "stm32g4xx_hal.h"
#include "tim.h"

#define COOLER_TIMER TIM8
#define HEATER_TIMER TIM1

/* ************************************************ */
/* Method name: 	   vCoolerfanPWMDuty      	    */
/*													*/
/* Method description: seta o duty cycle do Cooler  */
/*													*/
/* Input params:	   duty cycle do Cooler			*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vCoolerfanPWMDuty(float fCoolerDuty) {
	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, fCoolerDuty*(1000-1));
}

/* ************************************************ */
/* Method name: 	   vHeaterPWMDuty            	*/
/*													*/
/* Method description: seta o duty cycle do Heater  */
/*													*/
/* Input params:	   duty cycle do Heater			*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vHeaterPWMDuty(float fHeaterDuty) {
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1,fHeaterDuty*(1000-1));
}

/* ************************************************ */
/* Method name: 	   vInitCooler      	        */
/*													*/
/* Method description: init no cooler           	*/
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vInitCooler(){
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
}

/* ************************************************ */
/* Method name: 	   vStopCooler      			*/
/*													*/
/* Method description: para o cooler         		*/
/*													*/
/* Input params:	   n/a 							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vStopCooler(){
	HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_1);
}

/* ************************************************ */
/* Method name: 	   vInitHeater      	        */
/*													*/
/* Method description: init no heater           	*/
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vInitHeater(){
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

/* ************************************************ */
/* Method name: 	   vStopHeater      	        */
/*													*/
/* Method description: para o heater          		*/
/*													*/
/* Input params:	   n/a 							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vStopHeater(){
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
}

/* ***************************************************** */
/* Method name: 	   setupPWM                          */
/*													     */
/* Method description: inicializacao simultanea do       */
/* 						cooler e do heater               */
/*													     */
/* Input params:	   variável do tipo float relaciada  */
/*					   ao número digitado pelo usuário	 */
/*												         */
/* Output params:	   n/a 							     */
/* ***************************************************** */
void setupPWM() {
    vInitHeater();
    vInitCooler();
}

