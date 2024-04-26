#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "stm32g4xx_hal.h"

void vCommunicationInitCommunication(void);
void vCallbackCommunication(UART_HandleTypeDef *huart);
void vCommunicationCheckChar(void);
void vCommunicationProcessInput(void);
void vCommunicationTransmit(const unsigned char *t);

#endif // COMMUNICATION_H
