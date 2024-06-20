/* File name:        buttonsEvent.c                                              */
/* File description: Generate interruptions and events when you press a button */
/* Author name:      Henrique Akagi, Eduardo Siqueira e Lucas Pavarini      */
/* Creation date:    28mar2024                                              */
/* Revision date:    20 of June 2024                                                 */
/* ************************************************************************ */

#include "buttons.h"
#include "buttonsEvents.h"
#include "led.h"
#include "main.h"


// Pointers to the debounce and press time timers
extern TIM_HandleTypeDef *pTimDebouncerPointer, *pTimPressedTimePointer;

// Variable to store which button was pressed
extern char cWhatButton;

// Flags to indicate which buttons were pressed
extern char cUpFlag;
extern char cDownFlag;
extern char cLeftFlag;
extern char cRightFlag;
extern char cEnterFlag;

// Variables to store the time each button is pressed
int iBTCimaPressedTime = 0;
int iBTBaixoPressedTime = 0;
int iBTEsquerdaPressedTime = 0;
int iBTDireitaPressedTime = 0;
int iBTEnterPressedTime = 0;

// Flag to indicate if the long press timer is active
extern char cLongPressFlag;


/* ************************************************ */
/* Method name:       vButtonsEventsInit            */
/*                                                      */
/* Method description: Initializes the debounce and   */
/*                     press time timers              */
/*                                                      */
/* Input params:      pTimDebouncer - pointer to the  */
/*                     debounce timer                 */
/*                    pTimPressedTime - pointer to the */
/*                     press time timer               */
/*                                                      */
/* Output params:     n/a                             */
/* ************************************************ */
void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncer,
TIM_HandleTypeDef *pTimPressedTime){
	pTimDebouncerPointer = pTimDebouncer;
	pTimPressedTimePointer = pTimPressedTime;
}

/* ************************************************ */
/* Method name:       timerButtonsEventsDebouncingPeriodElapsedCallback */
/*                                                      */
/* Method description: Callback for the end of the    */
/*                     debounce period                */
/*                                                      */
/* Input params:      n/a                             */
/*                                                      */
/* Output params:     n/a                             */
/* ************************************************ */
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

/* ************************************************ */
/* Method name:       timerButtonsEventsLongPressPeriodElapsedCallback */
/*                                                      */
/* Method description: Callback for the end of the    */
/*                     long press period              */
/*                                                      */
/* Input params:      n/a                             */
/*                                                      */
/* Output params:     n/a                             */
/* ************************************************ */
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
