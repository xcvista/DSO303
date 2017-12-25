/*
 * rcc.c
 *
 *  Created on: Dec 25, 2017
 *      Author: technix
 */

#include <stm32f3xx.h>

void SystemInit(void)
{
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));

	RCC->CFGR = RCC_CFGR_PLLMUL9 | RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR_PPRE1_DIV2;
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));

	FLASH->ACR = FLASH_ACR_PRFTBE | (2 << FLASH_ACR_LATENCY_Pos);
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while (RCC->CFGR & RCC_CFGR_SWS != RCC_CFGR_SWS_PLL);
}
