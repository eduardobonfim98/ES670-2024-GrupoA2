


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
