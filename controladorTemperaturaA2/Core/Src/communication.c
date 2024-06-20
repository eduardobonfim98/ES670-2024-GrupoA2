/* File name:        communication.c                                              */
/* File description: UART Communication			   */
/* Author name:      Henrique Akagi, Eduardo Siqueira e Lucas Pavarini             */
/* Creation date:    24abril2024                                                    */
/* Revision date:    20 of June 2024                                                      */
/* ******************************************************************************* */

#include "communication.h"
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

extern UART_HandleTypeDef hlpuart1;
char c;
char inputBuffer[16] = {0};
int iCountDecimalPlaces = 0;
bool bDecimalPointSeen = false;
int iLenNumber = 0;

// **************************************************** //
// Method name:          vCommunicationInitCommunication //
// Method description:   Initializes the UART communication for receiving data via interrupts //
// Input params:         n/a                             //
// Output params:        n/a                             //
// **************************************************** //
void vCommunicationInitCommunication(void)
{
    memset(inputBuffer, 0, sizeof(inputBuffer));
    iLenNumber = 0;
    iCountDecimalPlaces = 0;
    bDecimalPointSeen = false;
    HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&c, 1);
}

// **************************************************** //
// Method name:          HAL_UART_RxCpltCallback        //
// Method description:   Callback automatically called when UART data is received  //
// Input params:         UART_HandleTypeDef *huart      //
// Output params:        n/a                             //
// **************************************************** //
void vCallbackCommunication(UART_HandleTypeDef *huart)
{
    if (huart == &hlpuart1)
    {
        HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&c, 1);

        if (c != '\n' && c != '\r') {
            HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *)&c, 1);

            vCommunicationCheckChar();
        } else {
            vCommunicationProcessInput();
        }
    }
}


// **************************************************** //
// Method name:          vCommunicationCheckChar        //
// Method description:   Checks and processes each character received via UART     //
// Input params:         n/a                             //
// Output params:        n/a                             //
// **************************************************** //
void vCommunicationCheckChar()
{
    if (c == ',' && !bDecimalPointSeen) {
        bDecimalPointSeen = true;
        inputBuffer[iLenNumber++] = c;
    } else if (bDecimalPointSeen && (c >= '0' && c <= '9')) {
        if (iCountDecimalPlaces < 3) {
            inputBuffer[iLenNumber++] = c;
            iCountDecimalPlaces++;
        }
    } else if (!bDecimalPointSeen && (c >= '0' && c <= '9')) {
        inputBuffer[iLenNumber++] = c;
    } else if (c == '-' && iLenNumber == 0) {
        inputBuffer[iLenNumber++] = c;
    }
}

// **************************************************** //
// Method name:          vCommunicationProcessInput     //
// Method description:   Processes the complete input stored in the buffer         //
// Input params:         n/a                             //
// Output params:        n/a                             //
// **************************************************** //
void vCommunicationProcessInput()
{
    for (int i = 0; i < iLenNumber; i++) {
        if (inputBuffer[i] == ',') inputBuffer[i] = '.';
    }

    double fNumber = atof(inputBuffer);
    char cTransmit[100];

    if (fNumber < -1000 || fNumber > 1000) {
        sprintf(cTransmit, "Numero fora do intervalo!\n");
    } else {
        sprintf(cTransmit, "Numero original: %.3f, Numero inverso: %.6f\n", fNumber, 1.0 / fNumber);
    }

    HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *)cTransmit, strlen(cTransmit));
    memset(inputBuffer, 0, sizeof(inputBuffer));
    iLenNumber = 0;
    iCountDecimalPlaces = 0;
    bDecimalPointSeen = false;
}

// **************************************************** //
// Method name:          vCommunicationTransmit         //
// Method description:   Sends the formatted string in the buffer                  //
// Input params:         const unsigned char *t         //
// Output params:        n/a                             //
// **************************************************** //
void vCommunicationTransmit(const unsigned char *t)
{
    HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *)t, strlen((const char *)t));
}
