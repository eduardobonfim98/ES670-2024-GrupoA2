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
#include <stdbool.h>

extern UART_HandleTypeDef hlpuart1;
char c;
char inputBuffer[16] = {0}; // 4 digitos pro numero, 3 pra casa decimal, 1 pra sinal de negativo
//1 pra virgula
int iCountDecimalPlaces = 0;
bool bDecimalPointSeen = false;
int iLenNumber = 0;

// ****************************************************//
// Nome da função:         vCommunicationInitCommunication //
// Descrição da função:    Inicializa a comunicação UART para //
//                         receber dados via interrupções.  //
// Parâmetros de entrada:  n/a                           //
// Parâmetros de saída:    n/a                          //
// ****************************************************//
void vCommunicationInitCommunication(void)
{
    memset(inputBuffer, 0, sizeof(inputBuffer));
    iLenNumber = 0;
    iCountDecimalPlaces = 0;
    bDecimalPointSeen = false;
    HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&c, 1);
}

// **************************************************** //
// Nome da função:         HAL_UART_RxCpltCallback      //
// Descrição da função:    Callback chamado automaticamente //
//                         quando dados UART são recebidos. //
// Parâmetros de entrada:  UART_HandleTypeDef *huart    //
// Parâmetros de saída:    n/a                          //
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
// Nome da função:         vCommunicationCheckChar      //
// Descrição da função:    Verifica e processa cada caractere //
//                         recebido através da UART.    //
// Parâmetros de entrada:  n/a                          //
// Parâmetros de saída:    n/a                          //
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
// Nome da função:         vCommunicationProcessInput	//
// Descrição da função:    Processa a entrada completa  //
//                         armazenada no buffer.        //
// Parâmetros de entrada:  n/a  						//
// Parâmetros de saída:    n/a							//
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
// Nome da função:         vCommunicationProcessInput  //
// Descrição da função:    Manda a string formatada    //
//                         no buffer.                 //
// Parâmetros de entrada:  n/a                        //
// Parâmetros de saída:    n/a                        //
// **************************************************** //
void vCommunicationTransmit(const unsigned char *t)
{
    HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *)t, strlen((const char *)t));
}
