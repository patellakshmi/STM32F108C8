/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: lakshmipatel
 */


#include "stm32f1xx_hal.h"
#include "main.h"

void SystemClockConfig();
void GPIO_Config();

int main(void){

	HAL_Init();
	SystemClockConfig();
	GPIO_Config();

	GPIOC->ODR = 0x0000;
	while(1){
		GPIOC->ODR = 0x0000;
		//HAL_Delay(1000);
		GPIOC->ODR = 0xFFFF;
		//HAL_Delay(1000);
	}

}

void SystemClockConfig(){

}

void GPIO_Config(){

	GPIO_InitTypeDef gpio;
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pin = GPIO_PIN_13 | GPIO_PIN_14;
	gpio.Pull = GPIO_PULLUP;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOC, &gpio);

	gpio.Pin = GPIO_PIN_2;
	HAL_GPIO_Init(GPIOC, &gpio);

}




