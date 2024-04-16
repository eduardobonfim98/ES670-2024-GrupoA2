/*
 * buttonsEvents.h
 *
 *  Created on: Apr 16, 2024
 *      Author: akira
 */

#ifndef INC_BUTTONSEVENTS_H_
#define INC_BUTTONSEVENTS_H_

#include "tim.h"

void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncer,
TIM_HandleTypeDef *pTimPressedTime);

void timerButtonsEventsDebouncingPeriodElapsedCallback();

void timerButtonsEventsLongPressPeriodElapsedCallback();

#endif /* INC_BUTTONSEVENTS_H_ */

