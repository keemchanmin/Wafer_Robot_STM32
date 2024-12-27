/*
 * uart_driver.h
 *
 *  Created on: Dec 22, 2024
 *      Author: A
 */

#ifndef INC_UART_DRIVER_H_
#define INC_UART_DRIVER_H_

#include "def.h"
#include "qbuffer.h"

#define HW_UART_MAX_CH		2
#define UART_MAX_CH         HW_UART_MAX_CH
#define _DEF_UART1				 0 //debuging
#define _DEF_UART2			     1 //sensor

bool     uartInit(void);
bool     uartOpen(uint8_t ch, uint32_t baud);
uint32_t uartAvailable(uint8_t ch);
uint8_t  uartRead(uint8_t ch);
uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length);
uint32_t uartPrintf(uint8_t ch, char *fmt, ...);
qbuffer_t *uartGetQBuffer(uint8_t ch);



#endif /* INC_UART_DRIVER_H_ */
