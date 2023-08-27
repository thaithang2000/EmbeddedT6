/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MOSI_DATA_0 		HAL_GPIO_WritePin(GPIOA, MOSI_Pin, GPIO_PIN_RESET)
#define MOSI_DATA_1 		HAL_GPIO_WritePin(GPIOA, MOSI_Pin, GPIO_PIN_SET)
#define SCLK_LOW				HAL_GPIO_WritePin(GPIOA, SCLK_Pin, GPIO_PIN_RESET)
#define SCLK_HIGH				HAL_GPIO_WritePin(GPIOA, SCLK_Pin, GPIO_PIN_SET)
#define CS_PIN_LOW			HAL_GPIO_WritePin(GPIOA, CS_Pin, GPIO_PIN_RESET)
#define CS_PIN_HIGH			HAL_GPIO_WritePin(GPIOA, CS_Pin, GPIO_PIN_SET)
#define READ_MISO_DATA	HAL_GPIO_ReadPin(GPIOA, MISO_Pin)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void spiSoftInit();	// Initialize SPI
void clockSignal();	// Initialize clock signal
void spiSoftMasterTransmit(uint8_t data);	// Transmit data to slave
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	char data_send[] = "HELLO_WORLD";
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	spiSoftInit();
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
			for (char i = 0; i <= 10 ; ++i)
			{
				
				spiSoftMasterTransmit(data_send[i]);
				//dataFromSlave = (int)spiSoftMasterReceive();
				HAL_Delay(2000);
				
			}
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, MOSI_Pin|SCLK_Pin|CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : MISO_Pin */
  GPIO_InitStruct.Pin = MISO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(MISO_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MOSI_Pin SCLK_Pin CS_Pin */
  GPIO_InitStruct.Pin = MOSI_Pin|SCLK_Pin|CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void spiSoftInit()
{
	HAL_GPIO_WritePin(GPIOA, MOSI_Pin, GPIO_PIN_RESET);	// set mosi pin low
	HAL_GPIO_WritePin(GPIOA, SCLK_Pin, GPIO_PIN_RESET);	// set sclk pin low
	HAL_GPIO_WritePin(GPIOA, CS_Pin, GPIO_PIN_SET);			// set cs pin high
}

void clockSignal()
{
	SCLK_HIGH;	// set sclk pin high
	__ASM volatile ("nop"::);	// do nothing operation
	HAL_Delay(100);
	SCLK_LOW;		// set sclk pin low
	__ASM volatile ("nop"::);	// do nothing operation
}

void spiSoftMasterTransmit(uint8_t data)
{
	uint8_t i = 0, x = 0;
	CS_PIN_LOW;
	for (i = 0; i < 8; ++i)
	{
		x = data & 0x80;
		if ( x > 0)
		{
			MOSI_DATA_1;
		}
		else
		{
			MOSI_DATA_0;
		}
		clockSignal();
		data = data << 1 ;
	}
	CS_PIN_HIGH;
}


uint8_t spiSoftMasterReceive()
{
	uint8_t data = 0x00, i = 0;
	CS_PIN_LOW;
	for (i = 0; i < 8; ++i)
	{
		clockSignal();
		HAL_Delay(10);
		data = data << 1;
		data = data | READ_MISO_DATA;
		
	}
	CS_PIN_HIGH;
	return data;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
