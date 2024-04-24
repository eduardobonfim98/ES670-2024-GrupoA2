/* File name:        communication.c                                              */
/* File description: arquivo para configuração da comunicacao UART				   */
/* Author name:      Henrique Akagi, Eduardo Siqueira e Lucas Pavarini             */
/* Creation date:    24abril2024                                                    */
/* Revision date:    24abril2024                                                    */
/* ******************************************************************************* */

#include "communication.h"
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef hlpuart1; // Assuming hlpuart1 is initialized elsewhere
char c;
char inputBuffer[12] = {0}; // 4 digitos pro numero, 3 pra casa decimal, 1 pra sinal de negativo
//1 pra virgula
int iLenNumber = 0;
int iCountCommas = 0;

// **************************************************** //
// Nome da função:         vCommunicationInitCommunication
// Descrição da função:    Inicializa a comunicação UART para
//                         receber dados via interrupções.
// Parâmetros de entrada:  n/a
// Parâmetros de saída:    n/a
// **************************************************** //
void vCommunicationInitCommunication(void)
{
    memset(inputBuffer, 0, sizeof(inputBuffer));
    iLenNumber = 0;
    iCountCommas = 0;
    HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&c, 1);
}

// **************************************************** //
// Nome da função:         HAL_UART_RxCpltCallback
// Descrição da função:    Callback chamado automaticamente
//                         quando dados UART são recebidos.
// Parâmetros de entrada:  UART_HandleTypeDef *huart
// Parâmetros de saída:    n/a
// **************************************************** //
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


// **************************************************** //
// Nome da função:         vCommunicationCheckChar
// Descrição da função:    Verifica e processa cada caractere
//                         recebido através da UART.
// Parâmetros de entrada:  n/a
// Parâmetros de saída:    n/a
// **************************************************** //
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

// **************************************************** //
// Nome da função:         vCommunicationProcessInput
// Descrição da função:    Processa a entrada completa armazenada
//                         no buffer.
// Parâmetros de entrada:  n/a
// Parâmetros de saída:    n/a
// **************************************************** //
void vCommunicationProcessInput()
{
    for (int i = 0; i < iLenNumber; i++) {
        if (inputBuffer[i] == ',') inputBuffers[i] = '.';
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

// **************************************************** //
// Nome da função:         vCommunicationProcessInput
// Descrição da função:    Manda a string formatada
//                         no buffer.
// Parâmetros de entrada:  n/a
// Parâmetros de saída:    n/a
// **************************************************** //
void vCommunicationTransmit(const unsigned char *t)
{
    HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *)t, strlen((const char *)t));
}
