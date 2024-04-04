/*
 * led.h
 *
 *  Created on: Apr 3, 2024
 *      Author: akira
 */

#ifndef INC_LED_H_
#define INC_LED_H_


#define LED_Yellow_Pin GPIO_PIN_4
#define LED_Yellow_GPIO_Port GPIOA
#define LED_Green1_Pin GPIO_PIN_5
#define LED_Green1_GPIO_Port GPIOA
#define LED_Red_Pin GPIO_PIN_14
#define LED_Red_GPIO_Port GPIOB
#define LED_Green2_Pin GPIO_PIN_12
#define LED_Green2_GPIO_Port GPIOA
#define LED_Blue_Pin GPIO_PIN_5
#define LED_Blue_GPIO_Port GPIOB

#define BIT_SET(a,b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL << (b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL << (b))))

enum declareLed{green1 = 1, yellow = 2, red = 3, green2 = 4, blue = 5};
void vLedInitLed ();
void vLedWriteLed (char, int);
void vLedOnLed (char);
void vLedOffLed (char);
void vLedToggleLed (char);

#endif /* INC_LED_H_ */
