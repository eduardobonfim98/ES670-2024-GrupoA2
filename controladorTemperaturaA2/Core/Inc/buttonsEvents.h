/*
 * buttonsEvents.h
 *
 *  Created on: Apr 16, 2024
 *      Author: akira
 */

#ifndef INC_BUTTONSEVENTS_H_
#define INC_BUTTONSEVENTS_H_

#include "tim.h"


// **************************************************** //
// Method name:         vButtonsEventsInit              //
// Method description:  Função que inicializa os        //
//                      recebe o ponteiro dos timers e  //
//                      guarda nas variáveis utilizadas //
//                                                      //
// Input params:       	pTimDebouncer,  pTimPressedTime //
// Output params:       n/a                             //
// **************************************************** //
void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncer,
TIM_HandleTypeDef *pTimPressedTime);


// ********************************************************************** //
// Method name:         timerButtonsEventsDebouncingPeriodElapsedCallback //
// Method description:  implementa a lógica de debouncing dos botões      //
//                                                                        //
// Input params:       	n/a                                               //
// Output params:       n/a                                               //
// ********************************************************************** //
void timerButtonsEventsDebouncingPeriodElapsedCallback();


// ********************************************************************** //
// Method name:         timerButtonsEventsLongPressPeriodElapsedCallback  //
// Method description:  supervisiona o tempo dos botões pressionados e    //
//                      aciona as callbacks de 500ms e 3000ms             //
// Input params:       	n/a                                               //
// Output params:       n/a                                               //
// ********************************************************************** //
void timerButtonsEventsLongPressPeriodElapsedCallback();


// ********************************************************************** //
// Method name:         vButtonsEventCallbackPressedEvent                 //
// Method description:  implementa a lógica de quando o botão é           //
//                      pressionado, incrementa em um o valor mostrado    //
//                      pelos leds                                        //
// Input params:        cBt                                               //
// Output params:       n/a                                               //
// ********************************************************************** //
void vButtonsEventCallbackPressedEvent(char cBt);


// ********************************************************************** //
// Method name:         vButtonsEventCallbackReleasedEvent                //
// Method description:  implementa a lógica de quando o botão é solto.    //
//                      Para este lab, não tem função operacional         //
// Input params:        cBt                                               //
// Output params:       n/a                                               //
// ********************************************************************** //
void vButtonsEventCallbackReleasedEvent(char cBt);


// ********************************************************************** //
// Method name:         vButtonsEventCallback500msPressedEvent            //
// Method description:  implementa a lógica de quando o botão é           //
//                      pressionado por mais de 500ms. Incrementa         //
//                      o valor mostrado pelos leds a cada 500ms          //
// Input params:        cBt                                               //
// Output params:       n/a                                               //
// ********************************************************************** //
void vButtonsEventCallback500msPressedEvent(char cBt);


// ********************************************************************** //
// Method name:         vButtonsEventCallback3sPressedEvent               //
// Method description:  implementa a lógica de quando o botão é           //
//                      pressionado por mais de 3000ms. Zera o valor      //
//                      mostrado pelos leds quando o botão enter é        //
//                      pressionado por 3000ms ou mais.                   //
// Input params:        cBt                                               //
// Output params:       n/a                                               //
// ********************************************************************** //
void vButtonsEventCallback3sPressedEvent(char cBt);

#endif /* INC_BUTTONSEVENTS_H_ */

