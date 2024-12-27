/*
 * current.c
 *
 *  Created on: Dec 22, 2024
 *      Author: A
 */


#include "current.h"

static ADC_HandleTypeDef *hadc_sensor;
static uint32_t adc_buffer[ADC_BUFFER_SIZE];
static float filter_buffer[FILTER_WINDOW_SIZE];
static uint8_t filter_index = 0;
static float filter_sum = 0;

void CurrentSensor_Init(ADC_HandleTypeDef *hadc) {
    hadc_sensor = hadc;
    for (uint8_t i = 0; i < FILTER_WINDOW_SIZE; i++) {
        filter_buffer[i] = 0;
    }
}

void CurrentSensor_Start(void) {
    HAL_ADC_Start_DMA(hadc_sensor, adc_buffer, ADC_BUFFER_SIZE);
}

float CurrentSensor_GetValue(void) {
    static uint32_t adc_sum = 0;
    for (uint8_t i = 0; i < ADC_BUFFER_SIZE; i++) {
        adc_sum += adc_buffer[i];
    }
    float adc_average = (float)adc_sum / ADC_BUFFER_SIZE;
    adc_sum = 0;

    filter_sum -= filter_buffer[filter_index];
    filter_buffer[filter_index] = adc_average;
    filter_sum += adc_average;
    filter_index = (filter_index + 1) % FILTER_WINDOW_SIZE;

    return filter_sum / FILTER_WINDOW_SIZE;
}
