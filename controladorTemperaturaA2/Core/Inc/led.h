/* File name:        led.h                                                  */
/* File description: arquivo para configuração dos regitradores dos leds    */
/* Author name:      Henrique Akagi, Eduardo Siqueira e Lucas Pavarini      */
/* Creation date:    28mar2024                                              */
/* Revision date:    28mar2024                                              */
/* ************************************************************************ */

#ifndef INC_LED_H_
#define INC_LED_H_


#define LED_Yellow_Pin GPIO_PIN_4
#define LED_Yellow_GPIO_Port GPIOA
#define LED_Green1_Pin GPIO_PIN_5
#define LED_Green1_GPIO_Port GPIOA
#define LED_Red_Pin GPIO_PIN_14
#define LED_Red_GPIO_Port GPIOB
#define LED_Green2_Pin GPIO_PIN_12
#define LED_Green2_GPIO_Port GPIOA
#define LED_Blue_Pin GPIO_PIN_5
#define LED_Blue_GPIO_Port GPIOB

#define BIT_SET(a,b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL << (b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL << (b))))

enum declareLed{green1 = 1, yellow = 2, red = 3, green2 = 4, blue = 5};

// **************************************************** //
// Method name:         vLedInitLed                     //
// Method description:  Função que inicializa os        //
//                      registradores, habilitando o    //
//                      clock e configurando os pinos   //
//                                                      //
// Input params:        n/a                             //
// Output params:       n/a                             //
// **************************************************** //
void vLedInitLed ();

// ***************************************************** //
// Method name:         vLedWriteLed                     //
// Method description:  Função que escreve o estado do   //
//                      led                              //
// Input params:        cLedNum:                         //
//                      indica qual led será escrito     //
//                      iLedWrite:                       //
//                      indica se o led será levado para //
//                      nível alto ou baixo              //
// Output params:       n/a                              //
// ***************************************************** //
void vLedWriteLed (char, int);

// ***************************************************** //
// Method name:         vLedOnLed                        //
// Method description:  Função que liga o led            //
// Input params:        cLedNum:                         //
//                                                       //
// Output params:       n/a                              //
// ***************************************************** //
void vLedOnLed (char);

// ***************************************************** //
// Method name:         vLedOffLed                       //
// Method description:  Função que desliga o led         //
// Input params:        cLedNum:                         //
//                                                       //
// Output params:       n/a                              //
// ***************************************************** //
void vLedOffLed (char);

// ******************************************************** //
// Method name:         vLedToggleLed                       //
// Method description:  Função que alterna o estado do led  //
//                                                          //
// Input params:        cLedNum:                            //
//                                                          //
// Output params:       n/a                                 //
// ******************************************************** //
void vLedToggleLed (char);

void vLedShowNumber(int button);

#endif /* INC_LED_H_ */
