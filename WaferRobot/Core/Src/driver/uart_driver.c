/*
 * uart_driver.c
 *
 *  Created on: Dec 22, 2024
 *      Author: A
 */


#include "uart_driver.h"

static bool is_open[UART_MAX_CH];
static qbuffer_t qbuffer[UART_MAX_CH];
static uint8_t rx_data[UART_MAX_CH];
static uint8_t rx_buf_1[256];
static uint8_t rx_buf_2[256];
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

bool uartInit(void)
{
  for (int i=0; i<UART_MAX_CH; i++)
  {
    is_open[i] = false;
  }


  return true;
}

bool uartOpen(uint8_t ch, uint32_t baud)
{
  bool ret = false;


  switch(ch)
  {
    case _DEF_UART1:

    	  huart3.Instance = USART3;
    	  huart3.Init.BaudRate = baud;
    	  huart3.Init.WordLength = UART_WORDLENGTH_8B;
    	  huart3.Init.StopBits = UART_STOPBITS_1;
    	  huart3.Init.Parity = UART_PARITY_NONE;
    	  huart3.Init.Mode = UART_MODE_TX_RX;
    	  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    	  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
    	  qbufferCreate(&qbuffer[ch], &rx_buf_1[0], 256);

    	  if (HAL_UART_Init(&huart2) != HAL_OK)
    	  {
    	    Error_Handler();
    	  }
    	  else
    	{
    		  ret= true;
    		  is_open[ch]=true;

    		  if(HAL_UART_Receive_IT(&huart3, (uint8_t *)&rx_data[_DEF_UART1], 1)!=HAL_OK)
    		  {
    			  ret =false;
    		  }

    	}

    	  break;

    case _DEF_UART2:

    	  huart2.Instance = USART2;
    	  huart2.Init.BaudRate = baud;
    	  huart2.Init.WordLength = UART_WORDLENGTH_8B;
    	  huart2.Init.StopBits = UART_STOPBITS_1;
    	  huart2.Init.Parity = UART_PARITY_NONE;
    	  huart2.Init.Mode = UART_MODE_TX_RX;
    	  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    	  huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    	  qbufferCreate(&qbuffer[ch], &rx_buf_2[0], 256);

    	  if (HAL_UART_Init(&huart2) != HAL_OK)
    	  {
    	    Error_Handler();
    	  }
    	  else
    	{
    		  ret= true;
    		  is_open[ch]=true;

    		  if(HAL_UART_Receive_IT(&huart2, (uint8_t *)&rx_data[_DEF_UART2], 1)!=HAL_OK)
    		  {
    			  ret =false;
    		  }

    	}

    	  break;
  }

  return ret;
}


uint32_t uartAvailable(uint8_t ch)
{
  uint32_t ret = 0;

  switch(ch)
  {
    case _DEF_UART1:
    	ret = qbufferAvailable(&qbuffer[ch]);
      break;

    case _DEF_UART2:
      ret = qbufferAvailable(&qbuffer[ch]);
      break;
  }

  return ret;
}

uint8_t uartRead(uint8_t ch)
{
  uint8_t ret = 0;

  switch(ch)
  {
    case _DEF_UART1:
    	qbufferRead(&qbuffer[_DEF_UART1], &ret, 1);
      break;

    case _DEF_UART2:
      qbufferRead(&qbuffer[_DEF_UART2], &ret, 1);
      break;
  }

  return ret;
}

uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
  uint32_t ret = 0;
  HAL_StatusTypeDef status;


  switch(ch)
  {
    case _DEF_UART1:
    	status = HAL_UART_Transmit(&huart3, p_data, length, 100);
        if (status == HAL_OK)
        {
          ret = length;
        }
      break;

    case _DEF_UART2:
      status = HAL_UART_Transmit(&huart2, p_data, length, 100);
      if (status == HAL_OK)
      {
        ret = length;
      }
      break;
  }

  return ret;
}

uint32_t uartPrintf(uint8_t ch, char *fmt, ...)
{
  char buf[256];
  va_list args;
  int len;
  uint32_t ret;

  va_start(args, fmt);
  len = vsnprintf(buf, 256, fmt, args);

  ret = uartWrite(ch, (uint8_t *)buf, len);

  va_end(args);


  return ret;
}



qbuffer_t *uartGetQBuffer(uint8_t ch)
{
    if (ch < UART_MAX_CH)
    {
        return &qbuffer[ch];
    }
    return NULL;
}




void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

  if (huart->Instance == USART2)
  {
    qbufferWrite(&qbuffer[_DEF_UART2], &rx_data[_DEF_UART2], 1);

    HAL_UART_Receive_IT(&huart2, (uint8_t *)&rx_data[_DEF_UART2], 1);
  }

  if (huart->Instance == USART3)
  {
    qbufferWrite(&qbuffer[_DEF_UART1], &rx_data[_DEF_UART1], 1);

    HAL_UART_Receive_IT(&huart3, (uint8_t *)&rx_data[_DEF_UART1], 1);
  }
}




