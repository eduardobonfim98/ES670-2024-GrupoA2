/* File name:        buttons.c                                              */
/* File description: arquivo para configuração dos regitradores dos botões  */
/* Author name:      Henrique Akagi, Eduardo Siqueira e Lucas Pavarini      */
/* Creation date:    28mar2024                                              */
/* Revision date:    28mar2024                                              */
/* ************************************************************************ */

#include "STM32g474xx.h";
#include "buttons.h"

/* ************************************************ */
/* Method name: 	   vButtonsInitButtons      	*/
/*													*/
/* Method description: inicializa os botões         */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vButtonsInitButtons(){

	RCC->AHB2ENR |= 0x00000006;

	GPIOB->MODER &= ~(0x00000003);
	GPIOC->MODER &= ~(0x000003FC);

	GPIOB->OTYPER &= ~(0x00000001);
	GPIOC->OTYPER &= ~(0x0000001E);

	GPIOB->OSPEEDR &= ~(0x00000003);
	GPIOC->OSPEEDR &= ~(0x000003FC);

	GPIOB->PUPDR &= ~(0x00000003);
	GPIOC->PUPDR &= ~(0x000003FC);

}

/* *********************************************************** */
/* Method name: 	   cButtonsGetState          	           */
/*													           */
/* Method description: verifica se o botão está pressionado    */
/*													           */
/* Input params:	   char indicando número do botão          */
/*													           */
/* Output params:	   estado representado por char            */
/* *********************************************************** */
char cButtonsGetState(char button){

    switch(button){
    case up:
        if(BIT_CHECK(GPIOC->IDR, 1)){
            return 1;
        }else{
            return 0;
        }
        break;
    case down:
        if(BIT_CHECK(GPIOC->IDR, 2)){
            return 1;
        }else{
            return 0;
        }
        break;
    case left:
        if(BIT_CHECK(GPIOC->IDR, 3)){
            return 1;
        }else{
            return 0;
        }
        break;
    case right:
        if(BIT_CHECK(GPIOC->IDR, 4)){
            return 1;
        }else{
            return 0;
        }
        break;
    case enter:
        if(BIT_CHECK(GPIOB->IDR, 0)){
            return 1;
        }else{
            return 0;
        }
        break;
    default:
        return 0; // Default case to handle unexpected button values
    }
}

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
char cButtonsGetNumber(){
	if(BIT_CHECK(GPIOC->IDR, 1)){
		return 1;
	}else if(BIT_CHECK(GPIOC->IDR, 2)){
		return 2;
	}else if(BIT_CHECK(GPIOC->IDR, 3)){
		return 3;
	}else if(BIT_CHECK(GPIOC->IDR, 4)){
		return 4;
	}else if(BIT_CHECK(GPIOB->IDR, 0)){
		return 5;
	}else{
		return 0;
	}
}
