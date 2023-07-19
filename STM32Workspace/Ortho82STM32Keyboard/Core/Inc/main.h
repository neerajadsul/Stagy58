/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32l0xx_hal.h"

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
#define USER_B1_Pin GPIO_PIN_13
#define USER_B1_GPIO_Port GPIOC
#define ROW_0_Pin GPIO_PIN_2
#define ROW_0_GPIO_Port GPIOC
#define ROW_1_Pin GPIO_PIN_3
#define ROW_1_GPIO_Port GPIOC
#define COL_0_Pin GPIO_PIN_1
#define COL_0_GPIO_Port GPIOB
#define COL_1_Pin GPIO_PIN_2
#define COL_1_GPIO_Port GPIOB
#define COL_2_Pin GPIO_PIN_11
#define COL_2_GPIO_Port GPIOB
#define COL_3_Pin GPIO_PIN_12
#define COL_3_GPIO_Port GPIOB
#define COL_4_Pin GPIO_PIN_13
#define COL_4_GPIO_Port GPIOB
#define COL_5_Pin GPIO_PIN_14
#define COL_5_GPIO_Port GPIOB
#define COL_6_Pin GPIO_PIN_15
#define COL_6_GPIO_Port GPIOB
#define ROW_2_Pin GPIO_PIN_6
#define ROW_2_GPIO_Port GPIOC
#define ROW_3_Pin GPIO_PIN_7
#define ROW_3_GPIO_Port GPIOC
#define ROW_4_Pin GPIO_PIN_8
#define ROW_4_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
