/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
int cursor1 = 0;
int cursor2 = 0;
int znak[4];


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  lcd_init ();

    lcd_put_cur(0, 3);
    lcd_send_string ("Translator");

    HAL_Delay(1000);

    lcd_put_cur(1, 2);

    lcd_send_string("Morse to ABC");

    HAL_Delay(2000);

    lcd_clear ();
   /* Infinite loop */
   /* USER CODE BEGIN WHILE */
   while (1)
   {
     /* USER CODE END WHILE */
 	  if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)== GPIO_PIN_RESET)
 	  	  {

	  	  lcd_put_cur(0, cursor1);
 	  	  lcd_send_string ("*");
           HAL_Delay(10);
           znak[cursor1] = 0;
           cursor1 ++;
 	  	  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
 	  	  HAL_Delay(1000);
 	  	  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);

 	  	  }
 	  if(HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin)== GPIO_PIN_RESET)
 	  	  	  {
 	  	  lcd_put_cur(0, cursor1);
 	  	  lcd_send_string ("-");
           HAL_Delay(10);
           znak[cursor1] = 1;
           cursor1 ++;
 	  	  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
 	  	  HAL_Delay(3000);
 	  	  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
 	  	  HAL_Delay(10);

 	  	  	  }
 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==1&&cursor1==2) //tworzenie litery a
 	 {
 		     HAL_Delay(250);
 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 		     lcd_put_cur(0,0);
 		 	 lcd_send_string ("               ");
             cursor1 =0;
 			 lcd_put_cur(1, cursor2);
 			 lcd_send_string ("a");
 			 cursor2++;
 			 HAL_Delay(100);
 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);


 	 }

 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==0&&znak[2]==0&&znak[3]==0&&cursor1==4) //tworzenie litery b
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("b");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }
 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==0&&znak[2]==1&&znak[3]==0&&cursor1==4) //tworzenie litery c
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("c");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }
 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==0&&znak[2]==0&&cursor1==3) //tworzenie litery d
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("d");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }
 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&cursor1==1) //tworzenie litery e
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("e");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }
 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==0&&znak[2]==1&&znak[3]==0&&cursor1==4) //tworzenie litery f
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("f");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }

 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==1&&znak[2]==0&&cursor1==3) //tworzenie litery g
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("g");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }

 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==0&&znak[2]==0&&znak[3]==0&&cursor1==4) //tworzenie litery h
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("h");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }

 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==0&&cursor1==2) //tworzenie litery i
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("i");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }

 	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==1&&znak[2]==1&&znak[3]==1&&cursor1==4) //tworzenie litery j
 	 	 {
 		         HAL_Delay(250);
 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 		     lcd_put_cur(0,0);
 	 		 	 lcd_send_string ("               ");
 	             cursor1 =0;
 	 			 lcd_put_cur(1, cursor2);
 	 			 lcd_send_string ("j");
 	 			 cursor2++;
 	 			 HAL_Delay(100);
 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 }

 	if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==0&&znak[2]==1&&cursor1==3) //tworzenie litery k
 	 	 	 {
 	 		         HAL_Delay(250);
 	 	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
 	 	 		     lcd_put_cur(0,0);
 	 	 		 	 lcd_send_string ("               ");
 	 	             cursor1 =0;
 	 	 			 lcd_put_cur(1, cursor2);
 	 	 			 lcd_send_string ("k");
 	 	 			 cursor2++;
 	 	 			 HAL_Delay(100);
 	 	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

 	 	 	 }

	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==1&&znak[2]==0&&znak[3]==0&&cursor1==4) //tworzenie litery l
	 	 {
		         HAL_Delay(250);
	 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	 		     lcd_put_cur(0,0);
	 		 	 lcd_send_string ("               ");
	             cursor1 =0;
	 			 lcd_put_cur(1, cursor2);
	 			 lcd_send_string ("l");
	 			 cursor2++;
	 			 HAL_Delay(100);
	 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==1&&cursor1==2) //tworzenie litery m
		 	 {
			         HAL_Delay(250);
		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		 		     lcd_put_cur(0,0);
		 		 	 lcd_send_string ("               ");
		             cursor1 =0;
		 			 lcd_put_cur(1, cursor2);
		 			 lcd_send_string ("m");
		 			 cursor2++;
		 			 HAL_Delay(100);
		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==0&&cursor1==2) //tworzenie litery n
			 	 {
				         HAL_Delay(250);
			 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
			 		     lcd_put_cur(0,0);
			 		 	 lcd_send_string ("               ");
			             cursor1 =0;
			 			 lcd_put_cur(1, cursor2);
			 			 lcd_send_string ("n");
			 			 cursor2++;
			 			 HAL_Delay(100);
			 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

			 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==1&&znak[2]==1&&cursor1==3) //tworzenie litery o
				 	 {
					         HAL_Delay(250);
				 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
				 		     lcd_put_cur(0,0);
				 		 	 lcd_send_string ("               ");
				             cursor1 =0;
				 			 lcd_put_cur(1, cursor2);
				 			 lcd_send_string ("o");
				 			 cursor2++;
				 			 HAL_Delay(100);
				 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

				 	 }

	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==1&&znak[2]==1&&znak[3]==0&&cursor1==4) //tworzenie litery p
		 	 {
			         HAL_Delay(250);
		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		 		     lcd_put_cur(0,0);
		 		 	 lcd_send_string ("               ");
		             cursor1 =0;
		 			 lcd_put_cur(1, cursor2);
		 			 lcd_send_string ("p");
		 			 cursor2++;
		 			 HAL_Delay(100);
		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

		 	 }

	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==1&&znak[2]==0&&znak[3]==1&&cursor1==4) //tworzenie litery q
	 		 	 {
	 			         HAL_Delay(250);
	 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	 		 		     lcd_put_cur(0,0);
	 		 		 	 lcd_send_string ("               ");
	 		             cursor1 =0;
	 		 			 lcd_put_cur(1, cursor2);
	 		 			 lcd_send_string ("q");
	 		 			 cursor2++;
	 		 			 HAL_Delay(100);
	 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==1&&znak[2]==0&&cursor1==3) //tworzenie litery r
		 		 	 {
		 			         HAL_Delay(250);
		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		 		 		     lcd_put_cur(0,0);
		 		 		 	 lcd_send_string ("               ");
		 		             cursor1 =0;
		 		 			 lcd_put_cur(1, cursor2);
		 		 			 lcd_send_string ("r");
		 		 			 cursor2++;
		 		 			 HAL_Delay(100);
		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==0&&znak[2]==0&&cursor1==3) //tworzenie litery s
	 		 		 	 {
	 		 			         HAL_Delay(250);
	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	 		 		 		     lcd_put_cur(0,0);
	 		 		 		 	 lcd_send_string ("               ");
	 		 		             cursor1 =0;
	 		 		 			 lcd_put_cur(1, cursor2);
	 		 		 			 lcd_send_string ("s");
	 		 		 			 cursor2++;
	 		 		 			 HAL_Delay(100);
	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	 		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&cursor1==1) //tworzenie litery t
	 	 		 		 	 {
	 	 		 			         HAL_Delay(250);
	 	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	 	 		 		 		     lcd_put_cur(0,0);
	 	 		 		 		 	 lcd_send_string ("               ");
	 	 		 		             cursor1 =0;
	 	 		 		 			 lcd_put_cur(1, cursor2);
	 	 		 		 			 lcd_send_string ("t");
	 	 		 		 			 cursor2++;
	 	 		 		 			 HAL_Delay(100);
	 	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	 	 		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==0&&znak[2]==1&&cursor1==3) //tworzenie litery u
	 	 	 		 		 	 {
	 	 	 		 			         HAL_Delay(250);
	 	 	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	 	 	 		 		 		     lcd_put_cur(0,0);
	 	 	 		 		 		 	 lcd_send_string ("               ");
	 	 	 		 		             cursor1 =0;
	 	 	 		 		 			 lcd_put_cur(1, cursor2);
	 	 	 		 		 			 lcd_send_string ("u");
	 	 	 		 		 			 cursor2++;
	 	 	 		 		 			 HAL_Delay(100);
	 	 	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	 	 	 		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==0&&znak[2]==0&&znak[3]==1&&cursor1==4) //tworzenie litery v
	 	 	 	 		 		 	 {
	 	 	 	 		 			         HAL_Delay(250);
	 	 	 	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	 	 	 	 		 		 		     lcd_put_cur(0,0);
	 	 	 	 		 		 		 	 lcd_send_string ("               ");
	 	 	 	 		 		             cursor1 =0;
	 	 	 	 		 		 			 lcd_put_cur(1, cursor2);
	 	 	 	 		 		 			 lcd_send_string ("v");
	 	 	 	 		 		 			 cursor2++;
	 	 	 	 		 		 			 HAL_Delay(100);
	 	 	 	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	 	 	 	 		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==0&&znak[1]==1&&znak[2]==1&&cursor1==3) //tworzenie litery w
	 	 	 	 	 		 		 	 {
	 	 	 	 	 		 			         HAL_Delay(250);
	 	 	 	 	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	 	 	 	 	 		 		 		     lcd_put_cur(0,0);
	 	 	 	 	 		 		 		 	 lcd_send_string ("               ");
	 	 	 	 	 		 		             cursor1 =0;
	 	 	 	 	 		 		 			 lcd_put_cur(1, cursor2);
	 	 	 	 	 		 		 			 lcd_send_string ("w");
	 	 	 	 	 		 		 			 cursor2++;
	 	 	 	 	 		 		 			 HAL_Delay(100);
	 	 	 	 	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	 	 	 	 	 		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==0&&znak[2]==0&&znak[3]==1&&cursor1==4) //tworzenie litery x
	 	 	 	 	 		 		 	 {
	 	 	 	 	 		 			         HAL_Delay(250);
	 	 	 	 	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	 	 	 	 	 		 		 		     lcd_put_cur(0,0);
	 	 	 	 	 		 		 		 	 lcd_send_string ("               ");
	 	 	 	 	 		 		             cursor1 =0;
	 	 	 	 	 		 		 			 lcd_put_cur(1, cursor2);
	 	 	 	 	 		 		 			 lcd_send_string ("x");
	 	 	 	 	 		 		 			 cursor2++;
	 	 	 	 	 		 		 			 HAL_Delay(100);
	 	 	 	 	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	 	 	 	 	 		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==0&&znak[2]==1&&znak[3]==1&&cursor1==4) //tworzenie litery y
		 	 	 	 	 		 		 	 {
		 	 	 	 	 		 			         HAL_Delay(250);
		 	 	 	 	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		 	 	 	 	 		 		 		     lcd_put_cur(0,0);
		 	 	 	 	 		 		 		 	 lcd_send_string ("               ");
		 	 	 	 	 		 		             cursor1 =0;
		 	 	 	 	 		 		 			 lcd_put_cur(1, cursor2);
		 	 	 	 	 		 		 			 lcd_send_string ("y");
		 	 	 	 	 		 		 			 cursor2++;
		 	 	 	 	 		 		 			 HAL_Delay(100);
		 	 	 	 	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

		 	 	 	 	 		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&znak[0]==1&&znak[1]==1&&znak[2]==0&&znak[3]==0&&cursor1==4) //tworzenie litery z
			 	 	 	 	 		 		 	 {
			 	 	 	 	 		 			         HAL_Delay(250);
			 	 	 	 	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
			 	 	 	 	 		 		 		     lcd_put_cur(0,0);
			 	 	 	 	 		 		 		 	 lcd_send_string ("               ");
			 	 	 	 	 		 		             cursor1 =0;
			 	 	 	 	 		 		 			 lcd_put_cur(1, cursor2);
			 	 	 	 	 		 		 			 lcd_send_string ("z");
			 	 	 	 	 		 		 			 cursor2++;
			 	 	 	 	 		 		 			 HAL_Delay(100);
			 	 	 	 	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

			 	 	 	 	 		 		 	 }
	 if(HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin)== GPIO_PIN_RESET&&cursor1==0) //tworzenie litery z
				 	 	 	 	 		 		 	 {
				 	 	 	 	 		 			         HAL_Delay(250);
				 	 	 	 	 		 		 		     HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
				 	 	 	 	 		 		 		     lcd_put_cur(0,0);
				 	 	 	 	 		 		 		 	 lcd_send_string ("               ");
				 	 	 	 	 		 		             cursor1 =0;
				 	 	 	 	 		 		 			 lcd_put_cur(1, cursor2);
				 	 	 	 	 		 		 			 lcd_send_string (" ");
				 	 	 	 	 		 		 			 cursor2++;
				 	 	 	 	 		 		 			 HAL_Delay(100);
				 	 	 	 	 		 		 			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

				 	 	 	 	 		 		 	 }
   }
   }


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
