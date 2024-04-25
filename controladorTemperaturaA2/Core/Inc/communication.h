#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "stm32g4xx_hal.h"

extern UART_HandleTypeDef hlpuart1;

void vCommunicationInitCommunication(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void vCommunicationCheckChar(void);
void vCommunicationProcessInput(void);
void vCommunicationTransmit(const unsigned char *t);

#endif // COMMUNICATION_H
