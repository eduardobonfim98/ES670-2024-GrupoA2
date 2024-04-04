/*
 * buttons.h
 *
 *  Created on: Apr 3, 2024
 *      Author: akira
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#define BT_Cima_Pin GPIO_PIN_1
#define BT_Cima_GPIO_Port GPIOC
#define BT_Baixo_Pin GPIO_PIN_2
#define BT_Baixo_GPIO_Port GPIOC
#define BT_Esquerda_Pin GPIO_PIN_3
#define BT_Esquerda_GPIO_Port GPIOC
#define BT_Direita_Pin GPIO_PIN_4
#define BT_Direita_GPIO_Port GPIOC
#define BT_Enter_Pin GPIO_PIN_0
#define BT_Enter_GPIO_Port GPIOB

#define BIT_SET(a,b) ((a) |= (1ULL << (b)))
#define BIT_RESET(a,b) ((a) &= ~(1ULL << (b)))
#define BIT_TOGGLE(a,b) ((a) ^= (1ULL << (b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL << (b))))

void vButtonsInitButtons();
char cButtonsGetState(char button);

//definição do enum:
enum declareButtons{up = 1, down = 2, right = 3, left = 4, enter = 5};


#endif /* INC_BUTTONS_H_ */
