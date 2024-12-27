/*
 * current.h
 *
 *  Created on: Dec 22, 2024
 *      Author: A
 */

#ifndef INC_CURRENT_H_
#define INC_CURRENT_H_

#include "def.h"

#define ADC_BUFFER_SIZE 128
#define FILTER_WINDOW_SIZE 16

void CurrentSensor_Init(ADC_HandleTypeDef *hadc);
void CurrentSensor_Start(void);
float CurrentSensor_GetValue(void);


#endif /* INC_CURRENT_H_ */
