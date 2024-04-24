// **************************************************** //
// File name:         communication.c                   //
// File description:                                    //
// Author name:       [Seu Nome]                        //
// Creation date:     20apr2023                         //
// Revision date:     27apr2023                         //
// **************************************************** //

#include "communication.h"
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef hlpuart1; // Assuming hlpuart1 is initialized elsewhere
char c;
char inputBuffer[12] = {0};
int iLenNumber = 0;
int iCountCommas = 0;

// Initializes UART communication to receive data via interrupts.
void vCommunicationInitCommunication(void)
{
    memset(inputBuffer, 0, sizeof(inputBuffer));
    iLenNumber = 0;
    iCountCommas = 0;
    HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&c, 1);
}

// Callback automatically called when a UART data is received.
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &hlpuart1)
    {
        // Continue to receive data via interrupt on hlpuart1
        HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&c, 1);

        if (c != '\n' && c != '\r') {
            // Echo the received character back to the sender
            HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *)&c, 1);

            vCommunicationCheckChar();
        } else {
            vCommunicationProcessInput();
        }
    }
}


// Verifies and processes each character received through UART.
void vCommunicationCheckChar()
{
    if (c == ',' && iCountCommas == 0 && iLenNumber <= 4) {
        iCountCommas++;
        inputBuffer[iLenNumber++] = c;
    } else if ((c >= '0' && c <= '9') && (iLenNumber < (iCountCommas ? 8 : 4))) {
        inputBuffer[iLenNumber++] = c;
    } else if (c == '-' && iLenNumber == 0) {
        inputBuffer[iLenNumber++] = c;
    }
}

// Processes the complete input stored in the buffer.
void vCommunicationProcessInput()
{
    for (int i = 0; i < iLenNumber; i++) {
        if (inputBuffer[i] == ',') inputBuffer[i] = '.';
    }

    float fNumber = atof(inputBuffer);
    char cTransmit[100];

    if (fNumber < -1000 || fNumber > 1000) {
        sprintf(cTransmit, "Numero fora do intervalo!\n");
    } else {
        sprintf(cTransmit, "Numero original: %f, Numero inverso: %.3f\n", fNumber, 1.0 / fNumber);
    }

    HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *)cTransmit, strlen(cTransmit));
    memset(inputBuffer, 0, sizeof(inputBuffer));
    iLenNumber = 0;
    iCountCommas = 0;
}

// Sends a formatted string through UART.
void vCommunicationTransmit(const unsigned char *t)
{
    HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *)t, strlen((const char *)t));
}
