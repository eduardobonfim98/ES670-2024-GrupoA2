/*
 * matrixKeyboard.c
 *
 *  Created on: Apr 4, 2024
 *      Author: aluno
 */

#include "matrixKeyboard.h"
#include "main.h"

xMatrixKeyboardState matrixKeyboardStruct;

void vMatrixKeyboardInit(){
	HAL_TIM_Base_Start_IT(&htim6);
}
xMatrixKeyboardState* pMatrixKeyboardGetKeys(){
	return matrixKeyboardStruct;
}

// Initialise the keyboard state
xMatrixKeyboardState xKeyboardState = {0}; // Initialise all members to 0

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    // Iterate over columns
    for (int i = 0; i < 4; i++) {
        // Turn on column
        HAL_GPIO_WritePin(col_ports[i], col_pins[i], GPIO_PIN_SET);

        // Check lines
        for (int j = 0; j < 4; j++) {
            if (HAL_GPIO_ReadPin(lin_ports[j], lin_pins[j]) == GPIO_PIN_SET) {
                // Update keyboard state for corresponding key to 1 if pressed
                switch (j) {
                    case 0:
                        switch (i) {
                            case 0: xKeyboardState.cNumberOne = 1; break;
                            case 1: xKeyboardState.cNumberTwo = 1; break;
                            case 2: xKeyboardState.cNumberThree = 1; break;
                            case 3: xKeyboardState.cLetterA = 1; break;
                        }
                        break;
                    case 1:
                        switch (i) {
                            case 0: xKeyboardState.cNumberFour = 1; break;
                            case 1: xKeyboardState.cNumberFive = 1; break;
                            case 2: xKeyboardState.cNumberSix = 1; break;
                            case 3: xKeyboardState.cLetterB = 1; break;
                        }
                        break;
                    case 2:
                        switch (i) {
                            case 0: xKeyboardState.cNumberSeven = 1; break;
                            case 1: xKeyboardState.cNumberEight = 1; break;
                            case 2: xKeyboardState.cNumberNine = 1; break;
                            case 3: xKeyboardState.cLetterC = 1; break;
                        }
                        break;
                    case 3:
                        switch (i) {
                            case 0: xKeyboardState.cSpecialCharacterStar = 1; break;
                            case 1: xKeyboardState.cSpecialCharacterHashtag = 1; break;
                            case 2: xKeyboardState.cNumberZero = 1; break;
                            case 3: xKeyboardState.cLetterD = 1; break;
                        }
                        break;
                }
            } else {
                // Update keyboard state for corresponding key to 0 if not pressed
                switch (j) {
                    case 0:
                        switch (i) {
                            case 0: xKeyboardState.cNumberOne = 0; break;
                            case 1: xKeyboardState.cNumberTwo = 0; break;
                            case 2: xKeyboardState.cNumberThree = 0; break;
                            case 3: xKeyboardState.cLetterA = 0; break;
                        }
                        break;
                    case 1:
                        switch (i) {
                            case 0: xKeyboardState.cNumberFour = 0; break;
                            case 1: xKeyboardState.cNumberFive = 0; break;
                            case 2: xKeyboardState.cNumberSix = 0; break;
                            case 3: xKeyboardState.cLetterB = 0; break;
                        }
                        break;
                    case 2:
                        switch (i) {
                            case 0: xKeyboardState.cNumberSeven = 0; break;
                            case 1: xKeyboardState.cNumberEight = 0; break;
                            case 2: xKeyboardState.cNumberNine = 0; break;
                            case 3: xKeyboardState.cLetterC = 0; break;
                        }
                        break;
                    case 3:
                        switch (i) {
                            case 0: xKeyboardState.cSpecialCharacterStar = 0; break;
                            case 1: xKeyboardState.cSpecialCharacterHashtag = 0; break;
                            case 2: xKeyboardState.cNumberZero = 0; break;
                            case 3: xKeyboardState.cLetterD = 0; break;
                        }
                        break;
                }
            }
        }

        // Turn off column
        HAL_GPIO_WritePin(col_ports[i], col_pins[i], GPIO_PIN_RESET);
    }
}
