/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "usart.h"
#include "tim.h"
#include "gpio.h"
#include "pid.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "buttons.h"
#include "led.h"
#include "matrixKeyboard.h"
#include "buttonsEvents.h"
#include "communicationStateMachine.h"
#include "temperatureSensor.h"
#include "lcd.h"
#include "heaterAndCooler.h"
#include "buzzer.h"
#include "tachometer.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */


/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

float fActualTemp;
float fDesiredTemp;
unsigned int uiCoolerSpeed;
unsigned char ucButtonState;
unsigned char ucDutyCycleCooler;
unsigned char ucDutyCycleHeather;
char cNumber = 0;
char cNumber500ms = 0;
extern unsigned char c;
char temp = 0x27;
float fSetPoint = 40;

xMatrixKeyboardState Teclado;

TIM_HandleTypeDef *pTimDebouncerPointer, *pTimPressedTimePointer;

//AD Conversor
extern ADC_HandleTypeDef hadc1;
extern unsigned long int adc_value;

//pressed buttons flags
char cUpFlag = 0;
char cDownFlag = 0;
char cLeftFlag = 0;
char cRightFlag = 0;
char cEnterFlag = 0;

//flag that shows when a button is pressed for a long period
char cLongPressFlag = 0;

//bin value shown by the LEds
int iLedValue = 0;
int iLedBinValue = 0;

//LCD variables
extern char cLCDAddress;
extern I2C_HandleTypeDef *hLCD;
extern unsigned char ucBackLight;
char cBufferLcd[2];
unsigned int uiTimerCounter = 0;
char strCounter[16]; // String buffer to hold the counter value

//Duty Cycles of Heater and Cooler
uint32_t uiHeaterCCRValue;
uint32_t uiCoolerCCRValue;
float fHeaterDuty = 0.00;
float fCoolerDuty = 1.00;

//buzzer set timer pointer, period and frequency
extern unsigned short int usBuzzerPeriod;
extern unsigned short int usBuzzerFrequency;
extern TIM_HandleTypeDef *pTimerBuzzer;

//tachometer rotations
extern unsigned short int usCoolerSpeed;
int teste;

//Temperature Sensor variables
extern float fTemperature;
char ucTemperature[50];
float timeCounter = 0.0f;

//Struct for PID
extern pid_data_type xPidConfig;
//buffers for PID printing
char cStrKp[16];
char cStrKi[16];
char cStrKd[16];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
float vTemperatureControl();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */


  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_LPUART1_UART_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  MX_TIM16_Init();
  MX_I2C1_Init();
  MX_TIM17_Init();
  MX_TIM1_Init();
  MX_TIM8_Init();
  MX_TIM5_Init();
  MX_TIM20_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_ADC1_Init();
  MX_TIM15_Init();
  /* USER CODE BEGIN 2 */

  //Communication State Machine
  vCommunicationStateMachineInit(&hlpuart1);

  //Led
  vLedInitLed ();

  //Buttons
  vButtonsInitButtons();

  //MatrixKeyboard
  vMatrixKeyboardInit();

  //Buttons Event
  vButtonsEventsInit(&htim7, &htim16);

  //Lcd
  vLcdInitLcd(&hi2c1, 0x27);
  vLcdSet();

  //Initialize Timer of counter (currently not being used)
  HAL_TIM_Base_Start_IT(&htim17);

  //Buzzer
  vBuzzerConfig(1000, 100, &htim5); // Input params: usFrequency - usPeriod - pointer to the buzzer timer

  //Heater and Cooler
  setupPWM();

  //vCoolerfanPWMDuty(fCoolerDuty);
  //vHeaterPWMDuty(fHeaterDuty);

  //Tachmeter
  vTachometerInit(&htim4, 500);

  //Inicialize AD conversor
  vTemperatureSensorInit(&hadc1);
  HAL_TIM_Base_Start_IT(&htim15); //Interruption for setting the frequency of the uart communication

  //PID
  vPidInit(32, 0.5, 7, 0.01, 1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) {

      HAL_Delay(1000);
      vLcdSetCursor(0,3);
      vLcdWriteString("     ");
      vLcdSetCursor(0,11);
      vLcdWriteString("     ");
      vLcdSetCursor(1,3);
      vLcdWriteString("     ");
      vLcdSetCursor(1,11);
      vLcdWriteString("     ");
      sprintf(cStrKp, "%.1f", xPidConfig.fKp);
      vLcdSetCursor(0,3);
      vLcdWriteString(cStrKp);

      sprintf(cStrKi, "%.1f", xPidConfig.fKi);
      vLcdSetCursor(0,11);
      vLcdWriteString(cStrKi);

      sprintf(cStrKd, "%.1f", xPidConfig.fKd);
      vLcdSetCursor(1,3);
      vLcdWriteString(cStrKd);

      fTemperature = fTemperatureSensorGetTemperature();
      sprintf(strCounter, "%.1f", fTemperature);
      vLcdSetCursor(1,11);
      vLcdWriteString(strCounter);


      /* Temperature Control */
      vTemperatureControl();


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart == &hlpuart1) {
        HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&c, 1);
        vCommunicationStateMachineProcessByteCommunication(c);
    }
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	pTimDebouncerPointer->Instance->CNT = 0;
	if (!cLongPressFlag){
		HAL_TIM_Base_Start_IT(pTimPressedTimePointer);
		cLongPressFlag = 1;
	}

	switch(GPIO_Pin){

		case BT_Cima_Pin:
			__HAL_GPIO_EXTI_CLEAR_IT(1);
			HAL_NVIC_DisableIRQ(BT_Cima_EXTI_IRQn);
			HAL_TIM_Base_Start_IT(pTimDebouncerPointer);
			cUpFlag = 1;
		break;
		case BT_Baixo_Pin:
			__HAL_GPIO_EXTI_CLEAR_IT(2);
			HAL_NVIC_DisableIRQ(BT_Baixo_EXTI_IRQn);
			HAL_TIM_Base_Start_IT(pTimDebouncerPointer);
			cDownFlag = 1;
		break;
		case BT_Esquerda_Pin:
			__HAL_GPIO_EXTI_CLEAR_IT(3);
			HAL_NVIC_DisableIRQ(BT_Esquerda_EXTI_IRQn);
			HAL_TIM_Base_Start_IT(pTimDebouncerPointer);
			cLeftFlag = 1;
		break;
		case BT_Direita_Pin:
			__HAL_GPIO_EXTI_CLEAR_IT(4);
			HAL_NVIC_DisableIRQ(BT_Direita_EXTI_IRQn);
			HAL_TIM_Base_Start_IT(pTimDebouncerPointer);
			cRightFlag = 1;
		break;
		case BT_Enter_Pin:
			__HAL_GPIO_EXTI_CLEAR_IT(0);
			HAL_NVIC_DisableIRQ(BT_Enter_EXTI_IRQn);
			HAL_TIM_Base_Start_IT(pTimDebouncerPointer);
			cEnterFlag = 1;
		break;
		}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
	if(htim == &htim6)
		vMatrixKeyboardRead();
	else
		if(htim == pTimDebouncerPointer)
			timerButtonsEventsDebouncingPeriodElapsedCallback();
		else
			if (htim == pTimPressedTimePointer)
				timerButtonsEventsLongPressPeriodElapsedCallback();
			else
				if (htim == &htim17)
					uiTimerCounter++;
				else
					if (htim == &htim5)
						vBuzzerStop();
					else
						if (htim == &htim4)
							vTachometerUpdate();
						else
							if (htim == &htim15){
						        float temperature = fTemperatureSensorGetTemperature();  // Obtém a temperatura
						        timeCounter += 0.1f;  // Incrementa o contador de tempo em 0.1 segundos (100 ms)

						        sprintf(ucTemperature, "t: %.1f, T: %.2f\n\r", timeCounter, temperature);

						        vCommunicationStateMachineTransmit(ucTemperature);
							}
	}

void vMatrixKeyboardHalfSecPressedCallback (char cButton){
	cNumber500ms += cButton;
	if(cNumber500ms >= 16){
		cNumber500ms = 0;
	}
	vLedShowNumber(cNumber500ms);
}

void vMatrixKeyboardThreeSecPressedCallback (char cButton){
	vLedToggleLed(5);
}

void vButtonsEventCallbackPressedEvent(char cBt){
	if (cBt == up){
		if(fCoolerDuty < 1){
			fCoolerDuty += 0.1;
			vCoolerfanPWMDuty(fCoolerDuty);
		}
	}else if(cBt == down){
		if(fCoolerDuty >= 0){
			fCoolerDuty -= 0.1;
			vCoolerfanPWMDuty(fCoolerDuty);
		}
	}else if(cBt == left){
		if(fHeaterDuty >= 0){
			fHeaterDuty -= 0.1;
			vHeaterPWMDuty(fHeaterDuty);
		}
	}else if(cBt == right){
		if(fHeaterDuty < 1){
			fHeaterDuty += 0.1;
			vHeaterPWMDuty(fHeaterDuty);
		}
	}
	vBuzzerPlay();
}

void vButtonsEventCallbackReleasedEvent(char cBt){

}

void vButtonsEventCallback500msPressedEvent(char cBt){
	if (cBt == up){
		iLedValue += 1;
		vLedShowNumber(iLedValue);
	}else if(cBt == down){
		iLedValue -= 1;
		vLedShowNumber(iLedValue);
	}
}

void vButtonsEventCallback3sPressedEvent(char cBt){
	if (cBt == enter){
		iLedValue = 0;
		vLedShowNumber(iLedBinValue);
	}
}

float vTemperatureControl()
{
  float fSensorValue, fcontrolEffort;

  fSensorValue = fTemperatureSensorGetTemperature();
  fcontrolEffort = fPidUpdateData(fSensorValue, fSetPoint);
  vHeaterPWMDuty(fcontrolEffort);
  return fcontrolEffort;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
