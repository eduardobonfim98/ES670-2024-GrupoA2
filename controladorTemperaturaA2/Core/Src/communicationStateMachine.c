#define IDDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define SEND '5'
#define VALUE '6'
#define SET2 '7'

#define MAX_VALUE_LENGTH 7

unsigned char ucUartState = IDDLE; // Variável que armazena o estado atual da UART.
unsigned char ucValueCount;  // Contador para o número de caracteres no valor recebido.


void processByteCommunication(unsigned char ucByte)
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
                if ('v'==ucByte || 'i'==ucByte ||
                    'f'==ucByte || 'p'==ucByte || 'a'==ucByte)
                {
                    ucParam = ucByte;
                    ucUartState = PARAM;
                }
                else
                    ucUartState = IDDLE;
                break;
            case SET:
                if ('v'==ucByte || 'i'==ucByte)
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
                    returnParam(ucParam);
                ucUartState = IDDLE;
                break;
            case VALUE:
                if ((ucByte>='0' && ucByte<='9') || ','==ucByte)
                {
                    if (ucValueCount < MAX_VALUE_LENGTH)
                        ucValue[ucValueCount++] = ucByte;
                }
                else
                {
                    if (';'==ucByte)
                    {
                        ucValue[ucValueCount] = '\0';
                        setParam(ucParam, ucValue);
                    }
                    ucUartState = IDDLE;
                }
                break;
            case SEND:
                if (';'==ucByte)
                    returnParam(ucParam);
                ucUartState = IDDLE;
                break;
            case SET2:
                if (';'==ucByte)
                    returnParam(ucParam);
                ucUartState = IDDLE;
                break;
        }
    }
}
