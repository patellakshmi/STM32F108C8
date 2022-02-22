/*
 * msp.c
 *
 *  Created on: Feb 22, 2022
 *      Author: lakshmipatel
 */


#include "stm32f1xx_hal.h"

void HAL_MspInit(void)
{

	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    SCB->HFSR |= 0x7 << 16;
    HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
    HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
    HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);

}


void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{

  //Enable the clock for UART peripheral
  __HAL_RCC_USART2_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  //Do the Pin Muxing Configuration
  GPIO_InitTypeDef gpio_uart;
  gpio_uart.Mode = GPIO_MODE_AF_PP;
  gpio_uart.Pin = GPIO_PIN_2;
  gpio_uart.Pull = GPIO_PULLUP;
  gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;

  //gpio_uart.
  HAL_GPIO_Init(GPIOA, &gpio_uart);

  gpio_uart.Pin = GPIO_PIN_3;
  HAL_GPIO_Init(GPIOA, &gpio_uart);
  //Set the NVIC ( IRQ - Setting )
  HAL_NVIC_EnableIRQ(USART2_IRQn);
  HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);

}
