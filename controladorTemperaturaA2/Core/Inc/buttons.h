/* File name:        buttons.c                                              */
/* File description: arquivo para configuração dos regitradores dos botões  */
/* Author name:      Henrique Akagi, Eduardo Siqueira e Lucas Pavarini      */
/* Creation date:    28mar2024                                              */
/* Revision date:    28mar2024                                              */
/* ************************************************************************ */


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

/* ************************************************ */
/* Method name: 	   vButtonsInitButtons      	*/
/*													*/
/* Method description: inicializa os botões         */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vButtonsInitButtons();

/* *********************************************************** */
/* Method name: 	   cButtonsGetState          	           */
/*													           */
/* Method description: verifica se o botão está pressionado    */
/*													           */
/* Input params:	   char indicando número do botão          */
/*													           */
/* Output params:	   estado representado por char            */
/* *********************************************************** */
char cButtonsGetState(char button);

/* ************************************************ */
/* Method name: 	   cButtonsGetNumber      	    */
/*													*/
/* Method description: retorna um char que representa
 * 						o número do botão           */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   char que representa o
 * 						número do botao				*/
/* ************************************************ */
char cButtonsGetNumber();

//definição do enum:
enum declareButtons{up = 1, down = 2, right = 3, left = 4, enter = 5};


#endif /* INC_BUTTONS_H_ */
