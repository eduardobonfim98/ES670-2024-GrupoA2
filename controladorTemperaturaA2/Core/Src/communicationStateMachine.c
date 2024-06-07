#include "communicationStateMachine.h"
#include "pid.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define IDDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define SEND '5'
#define VALUE '6'
#define SET2 '7'

#define MAX_VALUE_LENGTH 7
extern UART_HandleTypeDef hlpuart1;
unsigned char ucUartState = IDDLE; // Variável que armazena o estado atual da UART.
unsigned char ucValueCount;  // Contador para o número de caracteres no valor recebido.
extern unsigned char ucUartState;
extern unsigned char c;

extern float fActualTemp; // Variável para armazenar a temperatura atual
extern float fDesiredTemp; // Variável para armazenar a temperatura desejada
extern pid_data_type xPidConfig;
extern unsigned int uiCoolerSpeed; // Variável para armazenar a velocidade do cooler (0 - 100%)
extern unsigned char ucButtonState; // Variável para armazenar o estado dos botões (bloqueados ou liberados), 1 = liberado, 0 = bloqueado
extern unsigned char ucDutyCycleCooler; // Variável para armazenar o duty cycle do cooler (0 - 100%)
extern unsigned char ucDutyCycleHeather; // Variável para armazenar o duty cycle do heather (0 - 100%)

// **************************************************** //
// Method name:         vCommunicationInitCommunication //
// Method description:  Initiates the                   //
//                      global variables and the        //
//                      communication                   //
// Input params:        UART_HandleTypeDef *huart       //
// Output params:       n/a                             //
// **************************************************** //
void vCommunicationStateMachineInit(UART_HandleTypeDef *huart)
{
  HAL_UART_Receive_IT(&hlpuart1, (uint8_t *)&c, 1);
  fActualTemp = 20.0; //t
  fDesiredTemp = 25.0; //d
  ucButtonState = 1; //i
  uiCoolerSpeed = 10; // v
  ucDutyCycleCooler = 20; // c
  ucDutyCycleHeather = 50; // h
}

// ******************************************************************************** //
// Method name:         vCommunicationStateMachineProcessByteCommunication          //
// Method description:  Makes a state machine to receive data and call other        //
//                      functions to process the inputs.                            //
// Input params:        n/a                                                         //
// Output params:       n/a                                                         //
// ******************************************************************************** //
void vCommunicationStateMachineProcessByteCommunication(unsigned char ucByte)
{
    static unsigned char ucParam;
    static unsigned char ucValue[MAX_VALUE_LENGTH+1];
    if('#' == ucByte)
        ucUartState = READY;
    else if(IDDLE != ucUartState)
    {
        switch(ucUartState)
        {
            case READY:
                switch(ucByte)
                {
                    case 'g':
                        ucUartState = GET;
                        break;
                    case 's':
                        ucUartState = SET;
                        break;
                    default:
                        ucUartState = IDDLE;
                }
                break;
            case GET:
                if ('t'==ucByte || 'b'==ucByte ||
                    'c'==ucByte || 'h'==ucByte || 'v'==ucByte)
                {
                    ucParam = ucByte;
                    ucUartState = PARAM;
                }
                else
                    ucUartState = IDDLE;
                break;
            case SET:
            	//p = proporcional q = integrativo r = derivativo
                if ('p'==ucByte || 'i'==ucByte || 'd'==ucByte)
                {
                    ucParam = ucByte;
                    ucValueCount = 0;
                    ucUartState = VALUE;
                }
                else
                    ucUartState = IDDLE;
                break;
            case PARAM:
                if (';'==ucByte)
                	vCommunicationStateMachineReturnParam(ucParam);
                ucUartState = IDDLE;
                break;
            case VALUE:
                if ((ucByte>='0' && ucByte<='9') || ','==ucByte)
                {
                	if (',' == c)
                      c = '.';

                    if (ucValueCount < MAX_VALUE_LENGTH)
                        ucValue[ucValueCount++] = ucByte;
                }
                else
                {
                    if (';'==ucByte)
                    {
                        ucValue[ucValueCount] = '\0';
                        vCommunicationStateMachineSetParam(ucParam, ucValue);
                    }
                    ucUartState = IDDLE;
                }
                break;
        }
    }
}


// ******************************************************************* //
// Method name:         vCommunicationStateMachineReturnParam          //
// Method description:  Function that returns the param                //
// Input params:        unsigned char param                            //
// Output params:       n/a                                            //
// ******************************************************************* //
void vCommunicationStateMachineReturnParam(unsigned char param)
{
    char cTransmit[50];

    switch (param)
    {
        case 't':  // Temperatura atual
            sprintf(cTransmit, "%c=%.3f\n\r", param, fActualTemp);
            break;
        case 'b':  // Estado dos botões
            sprintf(cTransmit, "%c=%d\n\r", param, ucButtonState);
            break;
        case 'v':  // Velocidade do cooler
            sprintf(cTransmit, "%c=%d\n\r", param, uiCoolerSpeed);
            break;
        case 'h':  // Duty cycle do cooler
            sprintf(cTransmit, "%c=%d\n\r", param, ucDutyCycleHeather);
            break;
        case 'c':  // Duty cycle do cooler
            sprintf(cTransmit, "%c=%d\n\r", param, ucDutyCycleCooler);
            break;
    }
    vCommunicationStateMachineTransmit(cTransmit);
}

// ******************************************************************* //
// Method name:         vCommunicationStateMachineSetParam             //
// Method description:  Function that sets the desired temperature     //
//                      based on the received value                    //
// Input params:        unsigned char param, unsigned char *value      //
// Output params:       None                                           //
// ******************************************************************* //
void vCommunicationStateMachineSetParam(unsigned char param, unsigned char *value)
{
	unsigned char cTransmit[50];
    if (param == 'p'){
    	xPidConfig.fKp = atof((const char *)value);

    	sprintf((char*)cTransmit, "\n\rKp = %.3f\n\r", xPidConfig.fKp);
    }else if (param == 'i'){
    	xPidConfig.fKi = atof((const char *)value);

    	sprintf((char*)cTransmit, "\n\rKi = %.3f\n\r", xPidConfig.fKi);
    }else if (param == 'd'){
    	xPidConfig.fKd = atof((const char *)value);

    	sprintf((char*)cTransmit, "\n\rKd = %.3f\n\r", xPidConfig.fKd);
    }
    vCommunicationStateMachineTransmit((char*)cTransmit);
}

// ******************************************************************* //
// Method name:         vCommunicationStateMachineTransmit             //
// Method description:  Function that sends the processed data         //
//                      to PuTTY                                       //
// Input params:        unsigned char param, unsigned char *value      //
// Output params:       None                                           //
// ******************************************************************* //
void vCommunicationStateMachineTransmit(const char* data) {
	HAL_UART_Transmit_IT(&hlpuart1, (uint8_t *) data, strlen(data));
}


