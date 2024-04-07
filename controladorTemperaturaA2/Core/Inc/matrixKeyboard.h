/*
 * matrixKeyboard.h
 *
 *  Created on: Apr 4, 2024
 *      Author: aluno
 */

#ifndef INC_MATRIXKEYBOARD_H_
#define INC_MATRIXKEYBOARD_H_

typedef struct
{
  char cNumberOne;
  char cNumberTwo;
  char cNumberThree;
  char cNumberFour;
  char cNumberFive;
  char cNumberSix;
  char cNumberSeven;
  char cNumberEight;
  char cNumberNine;
  char cNumberZero;
  char cLetterA;
  char cLetterB;
  char cLetterC;
  char cLetterD;
  char cSpecialCharacterHashtag;
  char cSpecialCharacterStar;
} xMatrixKeyboardState;

void vMatrixKeyboardInit();

xMatrixKeyboardState pMatrixKeyboardGetKeys();

void vMatrixKeyboardRead();

#endif /* INC_MATRIXKEYBOARD_H_ */
