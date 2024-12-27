################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/default/adc.c \
../Core/Src/default/dma.c \
../Core/Src/default/gpio.c \
../Core/Src/default/tim.c 

OBJS += \
./Core/Src/default/adc.o \
./Core/Src/default/dma.o \
./Core/Src/default/gpio.o \
./Core/Src/default/tim.o 

C_DEPS += \
./Core/Src/default/adc.d \
./Core/Src/default/dma.d \
./Core/Src/default/gpio.d \
./Core/Src/default/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/default/%.o Core/Src/default/%.su Core/Src/default/%.cyclo: ../Core/Src/default/%.c Core/Src/default/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I"C:/Users/A/Desktop/Wafer_Robot-main/WaferRobot/Core/Inc/driver" -I"C:/Users/A/Desktop/Wafer_Robot-main/WaferRobot/Core/Inc/default" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-default

clean-Core-2f-Src-2f-default:
	-$(RM) ./Core/Src/default/adc.cyclo ./Core/Src/default/adc.d ./Core/Src/default/adc.o ./Core/Src/default/adc.su ./Core/Src/default/dma.cyclo ./Core/Src/default/dma.d ./Core/Src/default/dma.o ./Core/Src/default/dma.su ./Core/Src/default/gpio.cyclo ./Core/Src/default/gpio.d ./Core/Src/default/gpio.o ./Core/Src/default/gpio.su ./Core/Src/default/tim.cyclo ./Core/Src/default/tim.d ./Core/Src/default/tim.o ./Core/Src/default/tim.su

.PHONY: clean-Core-2f-Src-2f-default

