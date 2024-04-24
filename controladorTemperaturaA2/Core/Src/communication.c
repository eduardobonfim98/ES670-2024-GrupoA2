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

UART_HandleTypeDef *pCommunicationHuart;
char c;
char inputBuffer[12] = {0}; // Changed variable name and added initialization
int iLenNumber = 0;
int iCountCommas = 0;

// Inicializa a comunicação UART e prepara o sistema para receber dados de forma interrompida.
void vCommunicationInitCommunication(UART_HandleTypeDef *huart)
{
    pCommunicationHuart = huart;
    memset(inputBuffer, 0, sizeof(inputBuffer));
    iLenNumber = 0;
    iCountCommas = 0;
    HAL_UART_Receive_IT(huart, (uint8_t *)&c, 1);
}

// Callback chamada automaticamente quando um dado é recebido via UART.
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == pCommunicationHuart)
    {
        HAL_UART_Receive_IT(huart, (uint8_t *)&c, 1);
        if (c != '\n' && c != '\r') {
            vCommunicationCheckChar();
        } else {
            vCommunicationProcessInput();
        }
    }
}

// Verifica e processa cada caractere recebido através da UART.
void vCommunicationCheckChar()
{
    if (c == ',' && iCountCommas == 0 && iLenNumber <= 4) { // Apenas uma vírgula permitida
        iCountCommas++;
        inputBuffer[iLenNumber++] = c; // Colocar vírgula no buffer
    } else if ((c >= '0' && c <= '9') && (iLenNumber < (iCountCommas ? 8 : 4))) { // Limita tamanho antes/depois da vírgula
        inputBuffer[iLenNumber++] = c; // Colocar dígito no buffer
    } else if (c == '-' && iLenNumber == 0) { // Sinal de menos apenas no início
        inputBuffer[iLenNumber++] = c;
    }
}

// Processa a entrada completa armazenada no buffer.
void vCommunicationProcessInput()
{
    // Substituir vírgula por ponto para conversão
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

    HAL_UART_Transmit_IT(pCommunicationHuart, (uint8_t *)cTransmit, strlen(cTransmit));
    memset(inputBuffer, 0, sizeof(inputBuffer));
    iLenNumber = 0;
    iCountCommas = 0;
}

// Envia uma string formatada através da UART.
void vCommunicationTransmit(UART_HandleTypeDef *huart, const unsigned char *t)
{
    HAL_UART_Transmit_IT(huart, (uint8_t *)t, strlen((const char *)t));
}
