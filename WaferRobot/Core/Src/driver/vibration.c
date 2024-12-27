/*
 * vibration.c
 *
 *  Created on: Dec 27, 2024
 *      Author: A
 */

#include "vibration.h"

static qbuffer_t *uart_qbuffer;

void VibrationSensor_Init(uint8_t ch)
{
	uart_qbuffer = uartGetQBuffer(ch);
}
uint8_t* HandleVibration(void)
{
	uint8_t minimum_packet_size = 3;

	while (qbufferAvailable(&uart_qbuffer) >= minimum_packet_size)
	{
		uint8_t header[2];
		uint8_t length;

		qbufferRead(&uart_qbuffer, header, 2);
		qbufferRead(&uart_qbuffer, &length, 1);

		if (header[0] == 0xAA && header[1] == 0x55)
		{
			uint8_t total_packet_size = 3 + length;

			if (qbufferAvailable(&uart_qbuffer)
					>= (total_packet_size - minimum_packet_size))
			{
				VibrationSensor packet;

				memcpy(packet.header, header, 2);
				packet.length = length;
				qbufferRead(&uart_qbuffer, packet.data, length);

				return packet.data;
			}
			else
			{
				qbufferWrite(&uart_qbuffer, header, 2);
				qbufferWrite(&uart_qbuffer, &length, 1);
				break;
			}
		}
		else
		{
			continue;
		}
	}

	return NULL;
}
