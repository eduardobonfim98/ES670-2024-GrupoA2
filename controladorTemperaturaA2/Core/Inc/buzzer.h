/*
 * buzzer.h
 *
 *  Created on: May 15, 2024
 *      Author: akira
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

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
void vBuzzerConfig(unsigned short int usFrequency, unsigned short int usPeriod, TIM_HandleTypeDef *htim);

/* ************************************************ */
/* Method name: 	   vBuzzerPlay      			*/
/*													*/
/* Method description: inicializa o som do buzzer   */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vBuzzerPlay(void);

/* ************************************************ */
/* Method name: 	   vBuzzerStop      			*/
/*													*/
/* Method description: para o som do buzzer    		*/
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vBuzzerStop(void);


#endif /* INC_BUZZER_H_ */
