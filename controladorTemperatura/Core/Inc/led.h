/*
 * led.h
 *
 *  Created on: Apr 3, 2024
 *      Author: akira
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#define BIT_SET(a,b) ((a) |= (1ULL << (b)))
#define BIT_RESET(a,b) ((a) &= ~(1ULL << (b)))
#define BIT_TOGGLE(a,b) ((a) ^= (1ULL << (b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL << (b))))

enum declareLed{green1 = 1, yellow = 2, red = 3, green2 = 4, blue = 5};
void vLedInitLed ();
void vLedWriteLed (char, int);
void vLedOnLed (char);
void vLedOffLed (char);
void vLedToggleLed (char);

#endif /* INC_LED_H_ */
