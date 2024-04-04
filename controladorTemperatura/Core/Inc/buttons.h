/*
 * buttons.h
 *
 *  Created on: Apr 3, 2024
 *      Author: akira
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#define BIT_SET(a,b) ((a) |= (1ULL << (b)))
#define BIT_RESET(a,b) ((a) &= ~(1ULL << (b)))
#define BIT_TOGGLE(a,b) ((a) ^= (1ULL << (b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL << (b))))

void vButtonsInitButtons();
char cButtonsGetState(char button);

//definição do enum:
enum declareButtons{up = 1, down = 2, right = 3, left = 4, enter = 5};


#endif /* INC_BUTTONS_H_ */
