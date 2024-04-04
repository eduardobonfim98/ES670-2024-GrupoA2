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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define LPUART1_TX_Pin GPIO_PIN_2
#define LPUART1_TX_GPIO_Port GPIOA
#define LPUART1_RX_Pin GPIO_PIN_3
#define LPUART1_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
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
