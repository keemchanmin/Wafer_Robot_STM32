/*
 * vibration.h
 *
 *  Created on: Dec 27, 2024
 *      Author: A
 */

#ifndef INC_DRIVER_VIBRATION_H_
#define INC_DRIVER_VIBRATION_H_

#include "qbuffer.h"
#include "uart_driver.h"

#define UART_BUFFER_SIZE 256
#define PACKET_MAX_SIZE 64


typedef struct {
    uint8_t header[2];
    uint8_t length;
    uint8_t data[PACKET_MAX_SIZE];
} VibrationSensor;

void VibrationSensor_Init(uint8_t ch);
uint8_t* HandleVibration(void);

#endif /* INC_DRIVER_VIBRATION_H_ */
