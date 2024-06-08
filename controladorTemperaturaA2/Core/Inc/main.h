/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Aquecedor_PWM_Pin GPIO_PIN_0
#define Aquecedor_PWM_GPIO_Port GPIOC
#define BT_Cima_Pin GPIO_PIN_1
#define BT_Cima_GPIO_Port GPIOC
#define BT_Cima_EXTI_IRQn EXTI1_IRQn
#define BT_Baixo_Pin GPIO_PIN_2
#define BT_Baixo_GPIO_Port GPIOC
#define BT_Baixo_EXTI_IRQn EXTI2_IRQn
#define BT_Esquerda_Pin GPIO_PIN_3
#define BT_Esquerda_GPIO_Port GPIOC
#define BT_Esquerda_EXTI_IRQn EXTI3_IRQn
#define LPUART1_TX_Pin GPIO_PIN_2
#define LPUART1_TX_GPIO_Port GPIOA
#define LPUART1_RX_Pin GPIO_PIN_3
#define LPUART1_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define BT_Direita_Pin GPIO_PIN_4
#define BT_Direita_GPIO_Port GPIOC
#define BT_Direita_EXTI_IRQn EXTI4_IRQn
#define BT_Enter_Pin GPIO_PIN_0
#define BT_Enter_GPIO_Port GPIOB
#define BT_Enter_EXTI_IRQn EXTI0_IRQn
#define Buzzer_PWM_Pin GPIO_PIN_2
#define Buzzer_PWM_GPIO_Port GPIOB
#define Teclado_Lin4_Pin GPIO_PIN_11
#define Teclado_Lin4_GPIO_Port GPIOB
#define Teclado_Lin4_EXTI_IRQn EXTI15_10_IRQn
#define Teclado_Lin3_Pin GPIO_PIN_12
#define Teclado_Lin3_GPIO_Port GPIOB
#define Teclado_Lin3_EXTI_IRQn EXTI15_10_IRQn
#define Teclado_Lin2_Pin GPIO_PIN_13
#define Teclado_Lin2_GPIO_Port GPIOB
#define Teclado_Lin2_EXTI_IRQn EXTI15_10_IRQn
#define Teclado_Lin1_Pin GPIO_PIN_15
#define Teclado_Lin1_GPIO_Port GPIOB
#define Teclado_Lin1_EXTI_IRQn EXTI15_10_IRQn
#define Tacometro_TIM__Capture_Pin GPIO_PIN_6
#define Tacometro_TIM__Capture_GPIO_Port GPIOC
#define Teclado_Col4_Pin GPIO_PIN_7
#define Teclado_Col4_GPIO_Port GPIOC
#define Teclado_Col3_Pin GPIO_PIN_8
#define Teclado_Col3_GPIO_Port GPIOC
#define Teclado_Col2_Pin GPIO_PIN_9
#define Teclado_Col2_GPIO_Port GPIOC
#define Teclado_Col1_Pin GPIO_PIN_10
#define Teclado_Col1_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define Cooler_PWM_Pin GPIO_PIN_15
#define Cooler_PWM_GPIO_Port GPIOA
#define Tacometro_TIM__Ext_Clock_Pin GPIO_PIN_2
#define Tacometro_TIM__Ext_Clock_GPIO_Port GPIOD
#define T_SWO_Pin GPIO_PIN_3
#define T_SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
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


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
