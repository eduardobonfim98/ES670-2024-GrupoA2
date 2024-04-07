/*
 * matrixKeyboard.c
 *
 *  Created on: Apr 4, 2024
 *      Author: aluno
 */

xMatrixKeyboardState matrixKeyboardStruct;

char cColumnNumber = 1;

void vMatrixKeyboardInit(){
	HAL_TIM_Base_Start_IT(&htim6);
}

xMatrixKeyboardState* pMatrixKeyboardGetKeys(){
	return matrixKeyboardStruct;
}

void vMatrixKeyboardRead(){
	switch(cColumnNumber)
	{
		case 1:
			HAL_GPIO_WritePin(Teclado_Col1_GPIO_Port, Teclado_Col1_Pin, 1);

	}
}
