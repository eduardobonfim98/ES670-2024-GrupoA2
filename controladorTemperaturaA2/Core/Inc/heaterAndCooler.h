/*
 * heaterAndCooler.h
 *
 *  Created on: May 9, 2024
 *      Author: akira
 */

#ifndef INC_HEATERANDCOOLER_H_
#define INC_HEATERANDCOOLER_H_

/* ************************************************ */
/* Method name: 	   vCoolerfanPWMDuty      	    */
/*													*/
/* Method description: seta o duty cycle do Cooler  */
/*													*/
/* Input params:	   duty cycle do Cooler			*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vCoolerfanPWMDuty(float fCoolerDuty);

/* ************************************************ */
/* Method name: 	   vHeaterPWMDuty            	*/
/*													*/
/* Method description: seta o duty cycle do Heater  */
/*													*/
/* Input params:	   duty cycle do Heater			*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vHeaterPWMDuty(float fHeaterDuty);

/* ************************************************ */
/* Method name: 	   vInitCooler      	        */
/*													*/
/* Method description: init no cooler           	*/
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vInitCooler();

/* ************************************************ */
/* Method name: 	   vStopCooler      			*/
/*													*/
/* Method description: para o cooler         		*/
/*													*/
/* Input params:	   n/a 							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vStopCooler();

/* ************************************************ */
/* Method name: 	   vInitHeater      	        */
/*													*/
/* Method description: init no heater           	*/
/*													*/
/* Input params:	   n/a							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vInitHeater();

/* ************************************************ */
/* Method name: 	   vStopHeater              	*/
/*													*/
/* Method description: para o heater          		*/
/*													*/
/* Input params:	   n/a 							*/
/*													*/
/* Output params:	   n/a 							*/
/* ************************************************ */
void vStopHeater();

/* ***************************************************** */
/* Method name: 	   setupPWM                          */
/*													     */
/* Method description: inicializacao simultanea do       */
/* 						cooler e do heater               */
/*													     */
/* Input params:	   variável do tipo float relaciada  */
/*					   ao número digitado pelo usuário	 */
/*												         */
/* Output params:	   n/a 							     */
/* ***************************************************** */
void setupPWM();

#endif /* INC_HEATERANDCOOLER_H_ */
