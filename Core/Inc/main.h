/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

#include "stm32f3xx_ll_rcc.h"
#include "stm32f3xx_ll_bus.h"
#include "stm32f3xx_ll_system.h"
#include "stm32f3xx_ll_exti.h"
#include "stm32f3xx_ll_cortex.h"
#include "stm32f3xx_ll_utils.h"
#include "stm32f3xx_ll_pwr.h"
#include "stm32f3xx_ll_dma.h"
#include "stm32f3xx_ll_usart.h"
#include "stm32f3xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OSC32_IN_Pin LL_GPIO_PIN_14
#define OSC32_IN_GPIO_Port GPIOC
#define OSC32_OUT_Pin LL_GPIO_PIN_15
#define OSC32_OUT_GPIO_Port GPIOC
#define OSC_IN_Pin LL_GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOF
#define OSC_OUT_Pin LL_GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOF
#define B1_Pin LL_GPIO_PIN_0
#define B1_GPIO_Port GPIOA
#define LD4_Pin LL_GPIO_PIN_8
#define LD4_GPIO_Port GPIOE
#define LD3_Pin LL_GPIO_PIN_9
#define LD3_GPIO_Port GPIOE
#define LD5_Pin LL_GPIO_PIN_10
#define LD5_GPIO_Port GPIOE
#define LD7_Pin LL_GPIO_PIN_11
#define LD7_GPIO_Port GPIOE
#define LD9_Pin LL_GPIO_PIN_12
#define LD9_GPIO_Port GPIOE
#define LD10_Pin LL_GPIO_PIN_13
#define LD10_GPIO_Port GPIOE
#define LD8_Pin LL_GPIO_PIN_14
#define LD8_GPIO_Port GPIOE
#define LD6_Pin LL_GPIO_PIN_15
#define LD6_GPIO_Port GPIOE
#define SWDIO_Pin LL_GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin LL_GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
