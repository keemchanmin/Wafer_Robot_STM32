################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/driver/current.c \
../Core/Src/driver/qbuffer.c \
../Core/Src/driver/servo.c \
../Core/Src/driver/tcpClientRAW.c \
../Core/Src/driver/uart_driver.c \
../Core/Src/driver/vibration.c 

OBJS += \
./Core/Src/driver/current.o \
./Core/Src/driver/qbuffer.o \
./Core/Src/driver/servo.o \
./Core/Src/driver/tcpClientRAW.o \
./Core/Src/driver/uart_driver.o \
./Core/Src/driver/vibration.o 

C_DEPS += \
./Core/Src/driver/current.d \
./Core/Src/driver/qbuffer.d \
./Core/Src/driver/servo.d \
./Core/Src/driver/tcpClientRAW.d \
./Core/Src/driver/uart_driver.d \
./Core/Src/driver/vibration.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/driver/%.o Core/Src/driver/%.su Core/Src/driver/%.cyclo: ../Core/Src/driver/%.c Core/Src/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I"C:/Users/A/Desktop/Wafer_Robot-main/WaferRobot/Core/Inc/driver" -I"C:/Users/A/Desktop/Wafer_Robot-main/WaferRobot/Core/Inc/default" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-driver

clean-Core-2f-Src-2f-driver:
	-$(RM) ./Core/Src/driver/current.cyclo ./Core/Src/driver/current.d ./Core/Src/driver/current.o ./Core/Src/driver/current.su ./Core/Src/driver/qbuffer.cyclo ./Core/Src/driver/qbuffer.d ./Core/Src/driver/qbuffer.o ./Core/Src/driver/qbuffer.su ./Core/Src/driver/servo.cyclo ./Core/Src/driver/servo.d ./Core/Src/driver/servo.o ./Core/Src/driver/servo.su ./Core/Src/driver/tcpClientRAW.cyclo ./Core/Src/driver/tcpClientRAW.d ./Core/Src/driver/tcpClientRAW.o ./Core/Src/driver/tcpClientRAW.su ./Core/Src/driver/uart_driver.cyclo ./Core/Src/driver/uart_driver.d ./Core/Src/driver/uart_driver.o ./Core/Src/driver/uart_driver.su ./Core/Src/driver/vibration.cyclo ./Core/Src/driver/vibration.d ./Core/Src/driver/vibration.o ./Core/Src/driver/vibration.su

.PHONY: clean-Core-2f-Src-2f-driver

