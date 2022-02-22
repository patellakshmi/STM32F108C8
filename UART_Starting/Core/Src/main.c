/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: lakshmipatel
 */


#include "stm32f1xx_hal.h"
#include "main.h"


void Error_Handler();
void SystemClockConfig();
void UART_Init();

UART_HandleTypeDef uart;


int main(void){

	HAL_Init();
	SystemClockConfig();
	UART_Init();
	char *msg =  "Hi how are you";
	uint16_t len = strlen(msg);
	HAL_UART_Transmit(&uart, (uint8_t*)msg,len, HAL_MAX_DELAY);
	while(1);

}


void SystemClockConfig(){

}

void UART_Init(){
	uart.Instance = USART2;
	uart.Init.BaudRate = 115200;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.Mode = UART_MODE_TX_RX;
	if(HAL_UART_Init(&uart) != HAL_OK){
		Error_Handler();
	}
}


void Error_Handler(){
	while(1);
}
