/*
 * def.h
 *
 *  Created on: Dec 22, 2024
 *      Author: A
 */

#ifndef INC_DEF_H_
#define INC_DEF_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "stm32f4xx_hal.h"

#define		 _USE_HW_UART
#define      HW_UART_MAX_CH          2
#define 	_DEF_UART1				 0 //debuging
#define 	_DEF_UART2			     1 //sensor

#define 	_USE_HW_ADC
#define      HW_ADC_MAX_CH         2

#define 	_USE_HW_TIMER
#define      HW_TIMER_MAX_CH         2

#endif /* INC_DEF_H_ */
