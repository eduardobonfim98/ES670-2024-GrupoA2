/*
 * tachometer.h
 *
 *  Created on: May 15, 2024
 *      Author: akira
 */

#ifndef INC_TACHOMETER_H_
#define INC_TACHOMETER_H_

extern unsigned short int usCoolerSpeed;

extern unsigned int uiP;
extern TIM_HandleTypeDef *pTimerTachometer;

void vTachometerInit(TIM_HandleTypeDef *htim, unsigned int uiPeriod);

void vTachometerUpdate(void);



#endif /* INC_TACHOMETER_H_ */
