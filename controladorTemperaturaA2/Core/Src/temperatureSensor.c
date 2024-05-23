/* File name:        temperatureSensor.c                            */
/* File description:  		*/
/*								*/
/* Author name:      	            */
/* Creation date:    22may2024                                      */
/* Revision date:    22may2024                                      */
/* ***************************************************************** */


#include "adc.h"

uint16_t adc_value = 0;
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
void vTemperatureSensorInit(ADC_HandleTypeDef *hadc){
	HAL_ADC_Start_DMA(hadc, &adc_value, 1);

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
	fTemperatura = (((adc_value*3.25)/4095)*100);
	return fTemperatura;
}
