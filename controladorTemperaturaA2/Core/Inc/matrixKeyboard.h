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

typedef struct
{
	char cFlagNumberOne;
	char cFlagNumberTwo;
	char cFlagNumberThree;
	char cFlagNumberFour;
	char cFlagNumberFive;
	char cFlagNumberSix;
	char cFlagNumberSeven;
	char cFlagNumberEight;
	char cFlagNumberNine;
	char cFlagNumberZero;
	char cFlagLetterA;
	char cFlagLetterB;
	char cFlagLetterC;
	char cFlagLetterD;
	char cFlagSpecialCharacterHashtag;
	char cFlagSpecialCharacterStar;

	char c500NumberOne;
	char c500NumberTwo;
	char c500NumberThree;
	char c500NumberFour;
	char c500NumberFive;
	char c500NumberSix;
	char c500NumberSeven;
	char c500NumberEight;
	char c500NumberNine;
	char c500NumberZero;
	char c500LetterA;
	char c500LetterB;
	char c500LetterC;
	char c500LetterD;
	char c500SpecialCharacterHashtag;
	char c500SpecialCharacterStar;

	int i3000NumberOne;
	int i3000NumberTwo;
	int i3000NumberThree;
	int i3000NumberFour;
	int i3000NumberFive;
	int i3000NumberSix;
	int i3000NumberSeven;
	int i3000NumberEight;
	int i3000NumberNine;
	int i3000NumberZero;
	int i3000LetterA;
	int i3000LetterB;
	int i3000LetterC;
	int i3000LetterD;
	int i3000SpecialCharacterHashtag;
	int i3000SpecialCharacterStar;
} xMatrixKeyboardTime;

void vMatrixKeyboardInit();

xMatrixKeyboardState* pMatrixKeyboardGetKeys();

void vMatrixKeyboardRead();

void vMatrixKeyboardEvent();

void vMatrixKeyboardHalfSecPressedCallback (char cButton);

void vMatrixKeyboardThreeSecPressedCallback (char cButton);

char cMatrixKeyboardGetNumber(xMatrixKeyboardState mStruct);

#endif /* INC_MATRIXKEYBOARD_H_ */
