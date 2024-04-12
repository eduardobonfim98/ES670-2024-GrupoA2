/* File name:        matrixKeyboard.c                                              */
/* File description: arquivo para configuração do teclado matricial				   */
/* Author name:      Henrique Akagi, Eduardo Siqueira e Lucas Pavarini             */
/* Creation date:    11abril2024                                                    */
/* Revision date:    11abril2024                                                    */
/* ******************************************************************************* */

#include "matrixKeyboard.h"
#include "main.h"
#include "tim.h"

xMatrixKeyboardState matrixKeyboardStruct;

xMatrixKeyboardTime matrixKeyboardTimerStruct;

int iColumn = 1;



/* ************************************************ */
/* Method name: 	      vMatrixKeyboardInit    	*/
/*													*/
/* Method description: inicializa o teclado     	 */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vMatrixKeyboardInit(){
	HAL_TIM_Base_Start_IT(&htim6);

	matrixKeyboardStruct.cNumberOne = 0;
	matrixKeyboardStruct.cNumberTwo = 0;
	matrixKeyboardStruct.cNumberThree = 0;
	matrixKeyboardStruct.cNumberFour = 0;
	matrixKeyboardStruct.cNumberFive = 0;
	matrixKeyboardStruct.cNumberSix = 0;
	matrixKeyboardStruct.cNumberSeven = 0;
	matrixKeyboardStruct.cNumberEight = 0;
	matrixKeyboardStruct.cNumberNine = 0;
	matrixKeyboardStruct.cNumberZero = 0;
	matrixKeyboardStruct.cLetterA = 0;
	matrixKeyboardStruct.cLetterB = 0;
	matrixKeyboardStruct.cLetterC = 0;
	matrixKeyboardStruct.cLetterD = 0;
	matrixKeyboardStruct.cSpecialCharacterHashtag = 0;
	matrixKeyboardStruct.cSpecialCharacterStar = 0;

	matrixKeyboardTimerStruct.cFlagNumberOne = 0;
	matrixKeyboardTimerStruct.cFlagNumberTwo = 0;
	matrixKeyboardTimerStruct.cFlagNumberThree = 0;
	matrixKeyboardTimerStruct.cFlagNumberFour = 0;
	matrixKeyboardTimerStruct.cFlagNumberFive = 0;
	matrixKeyboardTimerStruct.cFlagNumberSix = 0;
	matrixKeyboardTimerStruct.cFlagNumberSeven = 0;
	matrixKeyboardTimerStruct.cFlagNumberEight = 0;
	matrixKeyboardTimerStruct.cFlagNumberNine = 0;
	matrixKeyboardTimerStruct.cFlagNumberZero = 0;
	matrixKeyboardTimerStruct.cFlagLetterA = 0;
	matrixKeyboardTimerStruct.cFlagLetterB = 0;
	matrixKeyboardTimerStruct.cFlagLetterC = 0;
	matrixKeyboardTimerStruct.cFlagLetterD = 0;
	matrixKeyboardTimerStruct.cFlagSpecialCharacterHashtag = 0;
	matrixKeyboardTimerStruct.cFlagSpecialCharacterStar = 0;

	matrixKeyboardTimerStruct.c500NumberOne = 0;
	matrixKeyboardTimerStruct.c500NumberTwo = 0;
	matrixKeyboardTimerStruct.c500NumberThree = 0;
	matrixKeyboardTimerStruct.c500NumberFour = 0;
	matrixKeyboardTimerStruct.c500NumberFive = 0;
	matrixKeyboardTimerStruct.c500NumberSix = 0;
	matrixKeyboardTimerStruct.c500NumberSeven = 0;
	matrixKeyboardTimerStruct.c500NumberEight = 0;
	matrixKeyboardTimerStruct.c500NumberNine = 0;
	matrixKeyboardTimerStruct.c500NumberZero = 0;
	matrixKeyboardTimerStruct.c500LetterA = 0;
	matrixKeyboardTimerStruct.c500LetterB = 0;
	matrixKeyboardTimerStruct.c500LetterC = 0;
	matrixKeyboardTimerStruct.c500LetterD = 0;
	matrixKeyboardTimerStruct.c500SpecialCharacterHashtag = 0;
	matrixKeyboardTimerStruct.c500SpecialCharacterStar = 0;

	matrixKeyboardTimerStruct.i3000NumberOne = 0;
	matrixKeyboardTimerStruct.i3000NumberTwo = 0;
	matrixKeyboardTimerStruct.i3000NumberThree = 0;
	matrixKeyboardTimerStruct.i3000NumberFour = 0;
	matrixKeyboardTimerStruct.i3000NumberFive = 0;
	matrixKeyboardTimerStruct.i3000NumberSix = 0;
	matrixKeyboardTimerStruct.i3000NumberSeven = 0;
	matrixKeyboardTimerStruct.i3000NumberEight = 0;
	matrixKeyboardTimerStruct.i3000NumberNine = 0;
	matrixKeyboardTimerStruct.i3000NumberZero = 0;
	matrixKeyboardTimerStruct.i3000LetterA = 0;
	matrixKeyboardTimerStruct.i3000LetterB = 0;
	matrixKeyboardTimerStruct.i3000LetterC = 0;
	matrixKeyboardTimerStruct.i3000LetterD = 0;
	matrixKeyboardTimerStruct.i3000SpecialCharacterHashtag = 0;
	matrixKeyboardTimerStruct.i3000SpecialCharacterStar = 0;


}
xMatrixKeyboardState* pMatrixKeyboardGetKeys(){
    return &matrixKeyboardStruct;
}


// Initialize the keyboard state
xMatrixKeyboardState xKeyboardState = {0}; // Initialize all members to 0


/* ************************************************ */
/* Method name: 	   vMatrixKeyboardRead      	*/
/*													*/
/* Method description: Lê o teclado                 */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */

void vMatrixKeyboardRead(){

  // switch the column to turn on and analyze

  switch (iColumn){
    case 1:
      // turn on column
      HAL_GPIO_WritePin(Teclado_Col1_GPIO_Port, Teclado_Col1_Pin, 1);
      if(HAL_GPIO_ReadPin(Teclado_Lin1_GPIO_Port, Teclado_Lin1_Pin) == 1){
          // Column 1 and Line 1 up
          matrixKeyboardStruct.cNumberOne = 1;
          matrixKeyboardStruct.cNumberFour = 0;
          matrixKeyboardStruct.cNumberSeven = 0;
          matrixKeyboardStruct.cSpecialCharacterStar = 0;

      }else if(HAL_GPIO_ReadPin(Teclado_Lin2_GPIO_Port, Teclado_Lin2_Pin) == 1){

          // Column 1 and Line 2 up

          matrixKeyboardStruct.cNumberOne = 0;
          matrixKeyboardStruct.cNumberFour = 1;
          matrixKeyboardStruct.cNumberSeven = 0;
          matrixKeyboardStruct.cSpecialCharacterStar = 0;

      }else if(HAL_GPIO_ReadPin(Teclado_Lin3_GPIO_Port, Teclado_Lin3_Pin) == 1){

          // Column 1 and Line 3 up

          matrixKeyboardStruct.cNumberOne = 0;
          matrixKeyboardStruct.cNumberFour = 0;
          matrixKeyboardStruct.cNumberSeven = 1;
          matrixKeyboardStruct.cSpecialCharacterStar = 0;

      }else if(HAL_GPIO_ReadPin(Teclado_Lin4_GPIO_Port, Teclado_Lin4_Pin) == 1){

          // Column 1 and Line 4 up

          matrixKeyboardStruct.cNumberOne = 0;
          matrixKeyboardStruct.cNumberFour = 0;
          matrixKeyboardStruct.cNumberSeven = 0;
          matrixKeyboardStruct.cSpecialCharacterStar = 1;

      }else{
          // No line up at Column 1
            matrixKeyboardStruct.cNumberOne = 0;
            matrixKeyboardStruct.cNumberFour = 0;
            matrixKeyboardStruct.cNumberSeven = 0;
            matrixKeyboardStruct.cSpecialCharacterStar = 0;
      }

      HAL_GPIO_WritePin(Teclado_Col1_GPIO_Port, Teclado_Col1_Pin, 0);
      break;

    case 2:

      // turn on column

    	HAL_GPIO_WritePin(Teclado_Col2_GPIO_Port, Teclado_Col2_Pin, 1);
		if(HAL_GPIO_ReadPin(Teclado_Lin1_GPIO_Port, Teclado_Lin1_Pin) == 1){
		  // Column 2 and Line 1 up
		  matrixKeyboardStruct.cNumberTwo = 1;
		  matrixKeyboardStruct.cNumberFive = 0;
		  matrixKeyboardStruct.cNumberEight = 0;
		  matrixKeyboardStruct.cNumberZero = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin2_GPIO_Port, Teclado_Lin2_Pin) == 1){

		  // Column 2 and Line 2 up

		  matrixKeyboardStruct.cNumberTwo = 0;
		  matrixKeyboardStruct.cNumberFive = 1;
		  matrixKeyboardStruct.cNumberEight = 0;
		  matrixKeyboardStruct.cNumberZero = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin3_GPIO_Port, Teclado_Lin3_Pin) == 1){

		  // Column 2 and Line 3 up

		  matrixKeyboardStruct.cNumberTwo = 0;
		  matrixKeyboardStruct.cNumberFive = 0;
		  matrixKeyboardStruct.cNumberEight = 1;
		  matrixKeyboardStruct.cNumberZero = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin4_GPIO_Port, Teclado_Lin4_Pin) == 1){

		  // Column 2 and Line 4 up

		  matrixKeyboardStruct.cNumberTwo = 0;
		  matrixKeyboardStruct.cNumberFive = 0;
		  matrixKeyboardStruct.cNumberEight = 0;
		  matrixKeyboardStruct.cNumberZero = 1;

		}else{
		  // No line up at Column 2
			matrixKeyboardStruct.cNumberTwo = 0;
			matrixKeyboardStruct.cNumberFive = 0;
			matrixKeyboardStruct.cNumberEight = 0;
			matrixKeyboardStruct.cNumberZero = 0;
		}
      // turn off column
      HAL_GPIO_WritePin(Teclado_Col2_GPIO_Port, Teclado_Col2_Pin, 0);
      break;

    case 3:
      // turn on column
		HAL_GPIO_WritePin(Teclado_Col3_GPIO_Port, Teclado_Col3_Pin, 1);
		if(HAL_GPIO_ReadPin(Teclado_Lin1_GPIO_Port, Teclado_Lin1_Pin) == 1){
		  // Column 3 and Line 1 up
		  matrixKeyboardStruct.cNumberThree = 1;
		  matrixKeyboardStruct.cNumberSix = 0;
		  matrixKeyboardStruct.cNumberNine = 0;
		  matrixKeyboardStruct.cSpecialCharacterHashtag = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin2_GPIO_Port, Teclado_Lin2_Pin) == 1){

		  // Column 3 and Line 2 up

		  matrixKeyboardStruct.cNumberThree = 0;
		  matrixKeyboardStruct.cNumberSix = 1;
		  matrixKeyboardStruct.cNumberNine = 0;
		  matrixKeyboardStruct.cSpecialCharacterHashtag = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin3_GPIO_Port, Teclado_Lin3_Pin) == 1){

		  // Column 3 and Line 3 up

		  matrixKeyboardStruct.cNumberThree = 0;
		  matrixKeyboardStruct.cNumberSix = 0;
		  matrixKeyboardStruct.cNumberNine = 1;
		  matrixKeyboardStruct.cSpecialCharacterHashtag = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin4_GPIO_Port, Teclado_Lin4_Pin) == 1){

		  // Column 3 and Line 4 up

		  matrixKeyboardStruct.cNumberThree = 0;
		  matrixKeyboardStruct.cNumberSix = 0;
		  matrixKeyboardStruct.cNumberNine = 0;
		  matrixKeyboardStruct.cSpecialCharacterHashtag = 1;

		}else{
		  // No line up at Column 3
			matrixKeyboardStruct.cNumberThree = 0;
			matrixKeyboardStruct.cNumberSix = 0;
			matrixKeyboardStruct.cNumberNine = 0;
			matrixKeyboardStruct.cSpecialCharacterHashtag = 0;
		}

      // turn on column
      HAL_GPIO_WritePin(Teclado_Col3_GPIO_Port, Teclado_Col3_Pin, 0);
      break;

    case 4:
      // turn on column
    	HAL_GPIO_WritePin(Teclado_Col4_GPIO_Port, Teclado_Col4_Pin, 1);
		if(HAL_GPIO_ReadPin(Teclado_Lin1_GPIO_Port, Teclado_Lin1_Pin) == 1){
		  // Column 4 and Line 1 up
		  matrixKeyboardStruct.cLetterA = 1;
		  matrixKeyboardStruct.cLetterB = 0;
		  matrixKeyboardStruct.cLetterC = 0;
		  matrixKeyboardStruct.cLetterD = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin2_GPIO_Port, Teclado_Lin2_Pin) == 1){

		  // Column 4 and Line 2 up

		  matrixKeyboardStruct.cLetterA = 0;
		  matrixKeyboardStruct.cLetterB = 1;
		  matrixKeyboardStruct.cLetterC = 0;
		  matrixKeyboardStruct.cLetterD = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin3_GPIO_Port, Teclado_Lin3_Pin) == 1){

		  // Column 4 and Line 3 up

		  matrixKeyboardStruct.cLetterA = 0;
		  matrixKeyboardStruct.cLetterB = 0;
		  matrixKeyboardStruct.cLetterC = 1;
		  matrixKeyboardStruct.cLetterD = 0;

		}else if(HAL_GPIO_ReadPin(Teclado_Lin4_GPIO_Port, Teclado_Lin4_Pin) == 1){

		  // Column 4 and Line 4 up

		  matrixKeyboardStruct.cLetterA = 0;
		  matrixKeyboardStruct.cLetterB = 0;
		  matrixKeyboardStruct.cLetterC = 0;
		  matrixKeyboardStruct.cLetterD = 1;

		}else{
		  // No line up at Column 4
			matrixKeyboardStruct.cLetterA = 0;
			matrixKeyboardStruct.cLetterB = 0;
			matrixKeyboardStruct.cLetterC = 0;
			matrixKeyboardStruct.cLetterD = 0;
		}
      // turn on column
      HAL_GPIO_WritePin(Teclado_Col4_GPIO_Port, Teclado_Col4_Pin, 0);
      break;
  }

  vMatrixKeyboardEvent();

  // change column number to next interruption

  iColumn++;
  if (iColumn > 4)
  {
    iColumn = 1;
  }
}

/* ************************************************ */
/* Method name: 	   vMatrixKeyboardEvent      	*/
/*													*/
/* Method description:          */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vMatrixKeyboardEvent(){

	//Botão 1:
	if (matrixKeyboardStruct.cNumberOne == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberOne++;
		if(matrixKeyboardTimerStruct.c500NumberOne >= 50){
			vMatrixKeyboardHalfSecPressedCallback(0);
			matrixKeyboardTimerStruct.c500NumberOne = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberOne++;
		if(matrixKeyboardTimerStruct.cFlagNumberOne == 0){
			if (matrixKeyboardTimerStruct.i3000NumberOne >= 300){
				vMatrixKeyboardThreeSecPressedCallback(0);
				matrixKeyboardTimerStruct.cFlagNumberOne = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberOne = 0;
		matrixKeyboardTimerStruct.i3000NumberOne = 0;
		matrixKeyboardTimerStruct.cFlagNumberOne = 0;
	}

	//Botão 2:
	if (matrixKeyboardStruct.cNumberTwo == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberTwo++;
		if(matrixKeyboardTimerStruct.c500NumberTwo >= 50){
			vMatrixKeyboardHalfSecPressedCallback(1);
			matrixKeyboardTimerStruct.c500NumberTwo = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberTwo++;
		if(matrixKeyboardTimerStruct.cFlagNumberTwo == 0){
			if (matrixKeyboardTimerStruct.i3000NumberTwo >= 300){
				vMatrixKeyboardThreeSecPressedCallback(1);
				matrixKeyboardTimerStruct.cFlagNumberTwo = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberTwo = 0;
		matrixKeyboardTimerStruct.i3000NumberTwo = 0;
		matrixKeyboardTimerStruct.cFlagNumberTwo = 0;
	}

	//Botão 3:
	if (matrixKeyboardStruct.cNumberThree == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberThree++;
		if(matrixKeyboardTimerStruct.c500NumberThree >= 50){
			vMatrixKeyboardHalfSecPressedCallback(2);
			matrixKeyboardTimerStruct.c500NumberThree = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberThree++;
		if(matrixKeyboardTimerStruct.cFlagNumberThree == 0){
			if (matrixKeyboardTimerStruct.i3000NumberThree >= 300){
				vMatrixKeyboardThreeSecPressedCallback(2);
				matrixKeyboardTimerStruct.cFlagNumberThree = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberThree = 0;
		matrixKeyboardTimerStruct.i3000NumberThree = 0;
		matrixKeyboardTimerStruct.cFlagNumberThree = 0;
	}

	//Botão 4:
	if (matrixKeyboardStruct.cNumberFour == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberFour++;
		if(matrixKeyboardTimerStruct.c500NumberFour >= 50){
			vMatrixKeyboardHalfSecPressedCallback(3);
			matrixKeyboardTimerStruct.c500NumberFour = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberFour++;
		if(matrixKeyboardTimerStruct.cFlagNumberFour == 0){
			if (matrixKeyboardTimerStruct.i3000NumberFour >= 300){
				vMatrixKeyboardThreeSecPressedCallback(3);
				matrixKeyboardTimerStruct.cFlagNumberFour = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberFour = 0;
		matrixKeyboardTimerStruct.i3000NumberFour = 0;
		matrixKeyboardTimerStruct.cFlagNumberFour = 0;
	}

	//Botão 5:
	if (matrixKeyboardStruct.cNumberFive == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberFive++;
		if(matrixKeyboardTimerStruct.c500NumberFive >= 50){
			vMatrixKeyboardHalfSecPressedCallback(4);
			matrixKeyboardTimerStruct.c500NumberFive = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberFive++;
		if(matrixKeyboardTimerStruct.cFlagNumberFive == 0){
			if (matrixKeyboardTimerStruct.i3000NumberFive >= 300){
				vMatrixKeyboardThreeSecPressedCallback(4);
				matrixKeyboardTimerStruct.cFlagNumberFive = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberFive = 0;
		matrixKeyboardTimerStruct.i3000NumberFive = 0;
		matrixKeyboardTimerStruct.cFlagNumberFive = 0;
	}

	//Botão 6:
	if (matrixKeyboardStruct.cNumberSix == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberSix++;
		if(matrixKeyboardTimerStruct.c500NumberSix >= 50){
			vMatrixKeyboardHalfSecPressedCallback(5);
			matrixKeyboardTimerStruct.c500NumberSix = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberSix++;
		if(matrixKeyboardTimerStruct.cFlagNumberSix == 0){
			if (matrixKeyboardTimerStruct.i3000NumberSix >= 300){
				vMatrixKeyboardThreeSecPressedCallback(5);
				matrixKeyboardTimerStruct.cFlagNumberSix = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberSix = 0;
		matrixKeyboardTimerStruct.i3000NumberSix = 0;
		matrixKeyboardTimerStruct.cFlagNumberSix = 0;
	}

	//Botão 7:
	if (matrixKeyboardStruct.cNumberSeven == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberSeven++;
		if(matrixKeyboardTimerStruct.c500NumberSeven >= 50){
			vMatrixKeyboardHalfSecPressedCallback(6);
			matrixKeyboardTimerStruct.c500NumberSeven = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberSeven++;
		if(matrixKeyboardTimerStruct.cFlagNumberSeven == 0){
			if (matrixKeyboardTimerStruct.i3000NumberSeven >= 300){
				vMatrixKeyboardThreeSecPressedCallback(6);
				matrixKeyboardTimerStruct.cFlagNumberSeven = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberSeven = 0;
		matrixKeyboardTimerStruct.i3000NumberSeven = 0;
		matrixKeyboardTimerStruct.cFlagNumberSeven = 0;
	}

	//Botão 8:
	if (matrixKeyboardStruct.cNumberEight == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberEight++;
		if(matrixKeyboardTimerStruct.c500NumberEight >= 50){
			vMatrixKeyboardHalfSecPressedCallback(7);
			matrixKeyboardTimerStruct.c500NumberEight = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberEight++;
		if(matrixKeyboardTimerStruct.cFlagNumberEight == 0){
			if (matrixKeyboardTimerStruct.i3000NumberEight >= 300){
				vMatrixKeyboardThreeSecPressedCallback(7);
				matrixKeyboardTimerStruct.cFlagNumberEight = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberEight = 0;
		matrixKeyboardTimerStruct.i3000NumberEight = 0;
		matrixKeyboardTimerStruct.cFlagNumberEight = 0;
	}

	//Botão 9:
	if (matrixKeyboardStruct.cNumberNine == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberNine++;
		if(matrixKeyboardTimerStruct.c500NumberNine >= 50){
			vMatrixKeyboardHalfSecPressedCallback(8);
			matrixKeyboardTimerStruct.c500NumberNine = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberNine++;
		if(matrixKeyboardTimerStruct.cFlagNumberNine == 0){
			if (matrixKeyboardTimerStruct.i3000NumberNine >= 300){
				vMatrixKeyboardThreeSecPressedCallback(8);
				matrixKeyboardTimerStruct.cFlagNumberNine = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberNine = 0;
		matrixKeyboardTimerStruct.i3000NumberNine = 0;
		matrixKeyboardTimerStruct.cFlagNumberNine = 0;
	}

	//Botão ZERO:
	if (matrixKeyboardStruct.cNumberZero == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500NumberZero++;
		if(matrixKeyboardTimerStruct.c500NumberZero >= 50){
			vMatrixKeyboardHalfSecPressedCallback(9);
			matrixKeyboardTimerStruct.c500NumberZero = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000NumberZero++;
		if(matrixKeyboardTimerStruct.cFlagNumberZero == 0){
			if (matrixKeyboardTimerStruct.i3000NumberZero >= 300){
				vMatrixKeyboardThreeSecPressedCallback(9);
				matrixKeyboardTimerStruct.cFlagNumberZero = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500NumberZero = 0;
		matrixKeyboardTimerStruct.i3000NumberZero = 0;
		matrixKeyboardTimerStruct.cFlagNumberZero = 0;
	}

	//Botão A:
	if (matrixKeyboardStruct.cLetterA == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500LetterA++;
		if(matrixKeyboardTimerStruct.c500LetterA >= 50){
			vMatrixKeyboardHalfSecPressedCallback(10);
			matrixKeyboardTimerStruct.c500LetterA = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000LetterA++;
		if(matrixKeyboardTimerStruct.cFlagLetterA == 0){
			if (matrixKeyboardTimerStruct.i3000LetterA >= 300){
				vMatrixKeyboardThreeSecPressedCallback(10);
				matrixKeyboardTimerStruct.cFlagLetterA = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500LetterA = 0;
		matrixKeyboardTimerStruct.i3000LetterA = 0;
		matrixKeyboardTimerStruct.cFlagLetterA = 0;
	}

	//Botão B:
	if (matrixKeyboardStruct.cLetterB == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500LetterB++;
		if(matrixKeyboardTimerStruct.c500LetterB >= 50){
			vMatrixKeyboardHalfSecPressedCallback(11);
			matrixKeyboardTimerStruct.c500LetterB = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000LetterB++;
		if(matrixKeyboardTimerStruct.cFlagLetterB == 0){
			if (matrixKeyboardTimerStruct.i3000LetterB >= 300){
				vMatrixKeyboardThreeSecPressedCallback(11);
				matrixKeyboardTimerStruct.cFlagLetterB = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500LetterB = 0;
		matrixKeyboardTimerStruct.i3000LetterB = 0;
		matrixKeyboardTimerStruct.cFlagLetterB = 0;
	}

	//Botão C:
	if (matrixKeyboardStruct.cLetterC == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500LetterC++;
		if(matrixKeyboardTimerStruct.c500LetterC >= 50){
			vMatrixKeyboardHalfSecPressedCallback(12);
			matrixKeyboardTimerStruct.c500LetterC = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000LetterC++;
		if(matrixKeyboardTimerStruct.cFlagLetterC == 0){
			if (matrixKeyboardTimerStruct.i3000LetterC >= 300){
				vMatrixKeyboardThreeSecPressedCallback(12);
				matrixKeyboardTimerStruct.cFlagLetterC = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500LetterC = 0;
		matrixKeyboardTimerStruct.i3000LetterC = 0;
		matrixKeyboardTimerStruct.cFlagLetterC = 0;
	}

	//Botão D:
	if (matrixKeyboardStruct.cLetterD == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500LetterD++;
		if(matrixKeyboardTimerStruct.c500LetterD >= 50){
			vMatrixKeyboardHalfSecPressedCallback(13);
			matrixKeyboardTimerStruct.c500LetterD = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000LetterD++;
		if(matrixKeyboardTimerStruct.cFlagLetterD == 0){
			if (matrixKeyboardTimerStruct.i3000LetterD >= 300){
				vMatrixKeyboardThreeSecPressedCallback(13);
				matrixKeyboardTimerStruct.cFlagLetterD = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500LetterD = 0;
		matrixKeyboardTimerStruct.i3000LetterD = 0;
		matrixKeyboardTimerStruct.cFlagLetterD = 0;
	}

	//Botão #:
	if (matrixKeyboardStruct.cSpecialCharacterHashtag == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500SpecialCharacterHashtag++;
		if(matrixKeyboardTimerStruct.c500SpecialCharacterHashtag >= 50){
			vMatrixKeyboardHalfSecPressedCallback(14);
			matrixKeyboardTimerStruct.c500SpecialCharacterHashtag = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000SpecialCharacterHashtag++;
		if(matrixKeyboardTimerStruct.cFlagSpecialCharacterHashtag == 0){
			if (matrixKeyboardTimerStruct.i3000SpecialCharacterHashtag >= 300){
				vMatrixKeyboardThreeSecPressedCallback(14);
				matrixKeyboardTimerStruct.cFlagSpecialCharacterHashtag = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500SpecialCharacterHashtag = 0;
		matrixKeyboardTimerStruct.i3000SpecialCharacterHashtag = 0;
		matrixKeyboardTimerStruct.cFlagSpecialCharacterHashtag = 0;
	}

	//Botão *:
	if (matrixKeyboardStruct.cSpecialCharacterStar == 1){
		//para 500ms:
		matrixKeyboardTimerStruct.c500SpecialCharacterStar++;
		if(matrixKeyboardTimerStruct.c500SpecialCharacterStar >= 50){
			vMatrixKeyboardHalfSecPressedCallback(15);
			matrixKeyboardTimerStruct.c500SpecialCharacterStar = 0;
		}
		//para 3000ms:
		matrixKeyboardTimerStruct.i3000SpecialCharacterStar++;
		if(matrixKeyboardTimerStruct.cFlagSpecialCharacterStar == 0){
			if (matrixKeyboardTimerStruct.i3000SpecialCharacterStar >= 300){
				vMatrixKeyboardThreeSecPressedCallback(15);
				matrixKeyboardTimerStruct.cFlagSpecialCharacterStar = 1;
			}
		}
	}else{
		matrixKeyboardTimerStruct.c500SpecialCharacterStar = 0;
		matrixKeyboardTimerStruct.i3000SpecialCharacterStar = 0;
		matrixKeyboardTimerStruct.cFlagSpecialCharacterStar = 0;
	}


}

__weak void vMatrixKeyboardHalfSecPressedCallback (char cButton) {
    // Function implementation
}

__weak void vMatrixKeyboardThreeSecPressedCallback (char cButton) {
    // Function implementation
}

/* ************************************************ */
/* Method name: 	   cMatrixKeyboardGetNumber    	*/
/*													*/
/* Method description:         */
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
char cMatrixKeyboardGetNumber(xMatrixKeyboardState mStruct){
	char temp;
	if (mStruct.cNumberZero == 1)
	{
	  temp = 0;
	}
	else if (mStruct.cNumberOne == 1)
	{
	  temp = 1;
	}
	else if (mStruct.cNumberTwo == 1)
	{
	  temp = 2;
	}
	else if (mStruct.cNumberThree == 1)
	{
	  temp = 3;
	}
	else if (mStruct.cNumberFour == 1)
	{
	  temp = 4;
	}
	else if (mStruct.cNumberFive == 1)
	{
	  temp = 5;
	}
	else if (mStruct.cNumberSix == 1)
	{
	  temp = 6;
	}
	else if (mStruct.cNumberSeven == 1)
	{
	  temp = 7;
	}
	else if (mStruct.cNumberEight == 1)
	{
	  temp = 8;
	}
	else if (mStruct.cNumberNine == 1)
	{
	  temp = 9;
	}
	else if (mStruct.cLetterA == 1)
	{
	  temp = 10;
	}
	else if (mStruct.cLetterB == 1)
	{
	  temp = 11;
	}
	else if (mStruct.cLetterC == 1)
	{
	  temp = 12;
	}
	else if (mStruct.cLetterD == 1)
	{
	  temp = 13;
	}
	else if (mStruct.cSpecialCharacterHashtag == 1)
	{
	  temp = 14;
	}
	else if (mStruct.cSpecialCharacterStar == 1)
	{
	  temp = 15;
	}

	return temp;
}

