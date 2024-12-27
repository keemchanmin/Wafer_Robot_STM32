/*
 * servo.h
 *
 *  Created on: Dec 22, 2024
 *      Author: A
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_


#include "def.h"

typedef enum {
    EXTEND,
    RETRACT,
    LEFT,
    RIGHT
} MotorAction;

void servo_Init(TIM_HandleTypeDef *htim_x, TIM_HandleTypeDef *htim_y);
void servo_PerformAction(MotorAction action);
void servo_ExecuteSequence(void);


#endif /* INC_SERVO_H_ */
