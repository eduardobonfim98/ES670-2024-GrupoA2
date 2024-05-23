#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "stm32g4xx_hal.h"

/* **************************************************** */
/* Method name:        vTemperatureSensorInit           */
/*                                                      */
/* Method description: The following method initializes */
/*                      the temperature sensor.         */
/*                                                      */
/* Input params:       ADC_HandleTypeDef *hadc          */
/* Output params:      n/a                              */
/* **************************************************** */
void vTemperatureSensorInit(ADC_HandleTypeDef *hadc);

/* ******************************************************** */
/* Method name:        fTemperatureSensorGetTemperature     */
/*                                                          */
/* Method description: returns the temperature sensor value */
/*                                                          */
/* Input params:       n/a                                  */
/* Output params:      float                                */
/* ******************************************************** */
float fTemperatureSensorGetTemperature();

#endif // TEMPERATURE_SENSOR_H
