/*
 * servo.c
 *
 *  Created on: Dec 22, 2024
 *      Author: A
 */


#include "servo.h"

static TIM_HandleTypeDef *htim_motor_x;
static TIM_HandleTypeDef *htim_motor_y;

void servo_Init(TIM_HandleTypeDef *htim_x, TIM_HandleTypeDef *htim_y) {
    htim_motor_x = htim_x;
    htim_motor_y = htim_y;

    HAL_TIM_PWM_Start(htim_motor_x, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(htim_motor_y, TIM_CHANNEL_1);

    servo_PerformAction(RETRACT);
}

void servo_PerformAction(MotorAction action) {
    switch (action) {
        case EXTEND:
            __HAL_TIM_SET_COMPARE(htim_motor_x, TIM_CHANNEL_1, 1500);
            __HAL_TIM_SET_COMPARE(htim_motor_y, TIM_CHANNEL_1, 1500);
            break;

        case RETRACT:
            __HAL_TIM_SET_COMPARE(htim_motor_x, TIM_CHANNEL_1, 1000);
            __HAL_TIM_SET_COMPARE(htim_motor_y, TIM_CHANNEL_1, 100);
            break;

        case LEFT:
            __HAL_TIM_SET_COMPARE(htim_motor_x, TIM_CHANNEL_1, 1250);
            __HAL_TIM_SET_COMPARE(htim_motor_y, TIM_CHANNEL_1, 1250);
            break;

        case RIGHT:
            __HAL_TIM_SET_COMPARE(htim_motor_x, TIM_CHANNEL_1, 1750);
            __HAL_TIM_SET_COMPARE(htim_motor_y, TIM_CHANNEL_1, 1750);
            break;

        default:
            __HAL_TIM_SET_COMPARE(htim_motor_x, TIM_CHANNEL_1, 0);
            __HAL_TIM_SET_COMPARE(htim_motor_y, TIM_CHANNEL_1, 0);
            break;
    }
}

void servo_ExecuteSequence(void) {
    Motor_PerformAction(EXTEND);
    HAL_Delay(1000);

    Motor_PerformAction(LEFT);
    HAL_Delay(500);

    Motor_PerformAction(RETRACT);
    HAL_Delay(1000);

    Motor_PerformAction(RIGHT);
    HAL_Delay(500);
}
