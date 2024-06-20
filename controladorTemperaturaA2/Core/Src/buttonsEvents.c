/*
 * buttonsEvents.c
 *
 *  Created on: Apr 16, 2024
 *      Author: akira
 */
#include "buttons.h"
#include "buttonsEvents.h"
#include "led.h"
#include "main.h"

extern TIM_HandleTypeDef *pTimDebouncerPointer, *pTimPressedTimePointer;

extern char cWhatButton;

//flags dos botões apertados
extern char cUpFlag;
extern char cDownFlag;
extern char cLeftFlag;
extern char cRightFlag;
extern char cEnterFlag;

//tempo que cada botão está apertado
int iBTCimaPressedTime = 0;
int iBTBaixoPressedTime = 0;
int iBTEsquerdaPressedTime = 0;
int iBTDireitaPressedTime = 0;
int iBTEnterPressedTime = 0;

//flag que indica se o timer dos botões está ativo
extern char cLongPressFlag;

void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncer,
TIM_HandleTypeDef *pTimPressedTime){
	pTimDebouncerPointer = pTimDebouncer;
	pTimPressedTimePointer = pTimPressedTime;
}


void timerButtonsEventsDebouncingPeriodElapsedCallback(){
	HAL_TIM_Base_Stop_IT(pTimDebouncerPointer);

	if (cUpFlag){
		__HAL_GPIO_EXTI_CLEAR_IT(BT_Cima_Pin);
		HAL_NVIC_EnableIRQ(BT_Cima_EXTI_IRQn);

		if(HAL_GPIO_ReadPin(BT_Cima_GPIO_Port, BT_Cima_Pin))
			vButtonsEventCallbackPressedEvent(up);
		else
			vButtonsEventCallbackReleasedEvent(up);
		cUpFlag = 0;
	}
	if (cDownFlag){
		__HAL_GPIO_EXTI_CLEAR_IT(BT_Baixo_Pin);
		HAL_NVIC_EnableIRQ(BT_Baixo_EXTI_IRQn);

		if(HAL_GPIO_ReadPin(BT_Baixo_GPIO_Port, BT_Baixo_Pin))
			vButtonsEventCallbackPressedEvent(down);
		else
			vButtonsEventCallbackReleasedEvent(down);
		cDownFlag = 0;
	}
	if (cLeftFlag){
		__HAL_GPIO_EXTI_CLEAR_IT(BT_Esquerda_Pin);
		HAL_NVIC_EnableIRQ(BT_Esquerda_EXTI_IRQn);

		if(HAL_GPIO_ReadPin(BT_Esquerda_GPIO_Port, BT_Esquerda_Pin))
			vButtonsEventCallbackPressedEvent(left);
		else
			vButtonsEventCallbackReleasedEvent(left);
		cLeftFlag = 0;
	}
	if (cRightFlag){
		__HAL_GPIO_EXTI_CLEAR_IT(BT_Direita_Pin);
		HAL_NVIC_EnableIRQ(BT_Direita_EXTI_IRQn);

		if(HAL_GPIO_ReadPin(BT_Direita_GPIO_Port, BT_Direita_Pin))
			vButtonsEventCallbackPressedEvent(right);
		else
			vButtonsEventCallbackReleasedEvent(right);
		cRightFlag = 0;
	}
	if (cEnterFlag){
		__HAL_GPIO_EXTI_CLEAR_IT(BT_Enter_Pin);
		HAL_NVIC_EnableIRQ(BT_Enter_EXTI_IRQn);

		if(HAL_GPIO_ReadPin(BT_Enter_GPIO_Port, BT_Enter_Pin))
			vButtonsEventCallbackPressedEvent(enter);
		else
			vButtonsEventCallbackReleasedEvent(enter);
		cEnterFlag = 0;
	}

}

void timerButtonsEventsLongPressPeriodElapsedCallback(){
	if(HAL_GPIO_ReadPin(BT_Cima_GPIO_Port, BT_Cima_Pin)){
		iBTCimaPressedTime += 10;
	}else{
		iBTCimaPressedTime = 0;
	}
	if(HAL_GPIO_ReadPin(BT_Baixo_GPIO_Port, BT_Baixo_Pin)){
		iBTBaixoPressedTime += 10;
	}else{
		iBTBaixoPressedTime = 0;
	}
	if(HAL_GPIO_ReadPin(BT_Esquerda_GPIO_Port, BT_Esquerda_Pin)){
		iBTEsquerdaPressedTime += 10;
	}else{
		iBTEsquerdaPressedTime = 0;
	}
	if(HAL_GPIO_ReadPin(BT_Direita_GPIO_Port, BT_Direita_Pin)){
		iBTDireitaPressedTime += 10;
	}else{
		iBTDireitaPressedTime = 0;
	}
	if(HAL_GPIO_ReadPin(BT_Enter_GPIO_Port, BT_Enter_Pin)){
		iBTEnterPressedTime += 10;
	}else{
		iBTEnterPressedTime = 0;
	}
	if(!HAL_GPIO_ReadPin(BT_Cima_GPIO_Port, BT_Cima_Pin) && !HAL_GPIO_ReadPin(BT_Baixo_GPIO_Port, BT_Baixo_Pin) && !HAL_GPIO_ReadPin(BT_Esquerda_GPIO_Port, BT_Esquerda_Pin) && !HAL_GPIO_ReadPin(BT_Direita_GPIO_Port, BT_Direita_Pin) && !HAL_GPIO_ReadPin(BT_Enter_GPIO_Port, BT_Enter_Pin)){
		HAL_TIM_Base_Stop_IT(pTimPressedTimePointer);
		cLongPressFlag = 0;
	}

	if((iBTCimaPressedTime % 500 == 0)&&(iBTCimaPressedTime != 0)){
		vButtonsEventCallback500msPressedEvent(up);
	}
	if((iBTBaixoPressedTime % 500 == 0)&&(iBTBaixoPressedTime != 0)){
		vButtonsEventCallback500msPressedEvent(down);
	}
	if((iBTEsquerdaPressedTime % 500 == 0)&&(iBTEsquerdaPressedTime != 0)){
		vButtonsEventCallback500msPressedEvent(left);
	}
	if(iBTDireitaPressedTime % 500 == 0 &&(iBTDireitaPressedTime != 0)){
		vButtonsEventCallback500msPressedEvent(right);
	}
	if(iBTEnterPressedTime % 500 == 0 &&(iBTEnterPressedTime != 0)){
		vButtonsEventCallback500msPressedEvent(enter);
	}

	if(iBTCimaPressedTime == 3000){
		vButtonsEventCallback3sPressedEvent(up);
	}
	if(iBTBaixoPressedTime == 3000){
		vButtonsEventCallback3sPressedEvent(down);
	}
	if(iBTEsquerdaPressedTime == 3000){
		vButtonsEventCallback3sPressedEvent(left);
	}
	if(iBTDireitaPressedTime == 3000){
		vButtonsEventCallback3sPressedEvent(right);
	}
	if(iBTEnterPressedTime == 3000){
		vButtonsEventCallback3sPressedEvent(enter);
	}
}

__weak void vButtonsEventCallbackPressedEvent(char cBt){
	// A implementação dessa função não deve ser feita aqui
	// Essa função deve ser redeclarada e implementada em outro arquivo

}

__weak void vButtonsEventCallbackReleasedEvent(char cBt){
	// A implementação dessa função não deve ser feita aqui
	// Essa função deve ser redeclarada e implementada em outro arquivo

}

__weak void vButtonsEventCallback500msPressedEvent(char cBt){
	// A implementação dessa função não deve ser feita aqui
	// Essa função deve ser redeclarada e implementada em outro arquivo

}

__weak void vButtonsEventCallback3sPressedEvent(char cBt){
	// A implementação dessa função não deve ser feita aqui
	// Essa função deve ser redeclarada e implementada em outro arquivo

}
