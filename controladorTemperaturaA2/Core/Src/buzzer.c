#include "main.h"
#include "buzzer.h"
#include "tim.h"

unsigned short int usBuzzerPeriod;
unsigned short int usBuzzerFrequency;
TIM_HandleTypeDef *pTimerBuzzer;

/* ************************************************ */
/* Method name: 	   vBuzzerConfig      			*/
/*													*/
/* Method description: configuracao do buzzer       */
/*													*/
/* Input params:	   frequencia, periodo e timer  */
/* 						 do buzzer					*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vBuzzerConfig(unsigned short int usFrequency, unsigned short int usPeriod, TIM_HandleTypeDef *htim){
	pTimerBuzzer = htim;
	usBuzzerPeriod = usPeriod;
	usBuzzerFrequency = usFrequency;
	__HAL_TIM_SET_AUTORELOAD(pTimerBuzzer, usPeriod-1);
	__HAL_TIM_SET_COMPARE(pTimerBuzzer, TIM_CHANNEL_1, usFrequency-1);
}

/* ************************************************ */
/* Method name: 	   vBuzzerPlay      			*/
/*													*/
/* Method description: inicializa o som do buzzer   */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vBuzzerPlay(void){
	pTimerBuzzer->Instance->CNT = 0;
	HAL_TIM_Base_Start_IT(pTimerBuzzer);
	HAL_TIM_PWM_Start(pTimerBuzzer, TIM_CHANNEL_1);
}

/* ************************************************ */
/* Method name: 	   vBuzzerStop      			*/
/*													*/
/* Method description: para o som do buzzer    		*/
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vBuzzerStop(void){
	HAL_TIM_PWM_Stop(pTimerBuzzer, TIM_CHANNEL_1);
}

