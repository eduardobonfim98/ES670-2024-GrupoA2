#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "stm32g4xx_hal.h" // Ensure you include the appropriate HAL library header for STM32G4 series.

// Global variables used for UART communication
extern UART_HandleTypeDef *pCommunicationHuart;
extern char c;
extern char inputBuffer[12];
extern int iLenNumber;
extern int iCountCommas;

// Function to initialize UART communication and set up interrupt-based reception
void vCommunicationInitCommunication(UART_HandleTypeDef *huart);

// Callback function called when a UART receive interrupt occurs
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

// Function to process each character received via UART
void vCommunicationCheckChar();

// Function to process the full input once a complete number is received
void vCommunicationProcessInput();

// Function to send formatted string through UART
void vCommunicationTransmit(UART_HandleTypeDef *huart, const unsigned char *t);

#endif // COMMUNICATION_H
