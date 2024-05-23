/* File name:        temperatureSensor.c                            */
/* File description:  		*/
/*								*/
/* Author name:      	            */
/* Creation date:    22may2024                                      */
/* Revision date:    22may2024                                      */
/* ***************************************************************** */


#include "adc.h"

unsigned long int  adc_value = 0;
float fTemperatura;

/* **************************************************** */
/* Method name:        vTemperatureSensorInit           */
/*                                                      */
/* Method description: The following method initializes */
/*                      the temperature sensor.         */
/*                                                      */
/* Input params:       ADC_HandleTypeDef *hadc          */
/* Output params:      n/a                              */
/* **************************************************** */
void vTemperatureSensorInit(ADC_HandleTypeDef *hadc1){
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(hadc1, &adc_value, 1);
}

/* ******************************************************** */
/* Method name:        fTemperatureSensorGetTemperature     */
/*                                                          */
/* Method description: returns the temperature sensor value */
/*                                                          */
/* Input params:       n/a                                  */
/* Output params:      float                                */
/* ******************************************************** */
float fTemperatureSensorGetTemperature(){
	fTemperatura = ((325.0*(float) adc_value)/4095);
	return fTemperatura;
}
