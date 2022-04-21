################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/ADC.c \
../Inc/usart.c 

OBJS += \
./Inc/ADC.o \
./Inc/usart.o 

C_DEPS += \
./Inc/ADC.d \
./Inc/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32H7SINGLE -DSTM32H723ZGTx -DSTM32H7 -c -I../Inc -I"C:/Users/aymen/Desktop/Kraya/Isac/Chip_Headers/CMSIS/Device/ST/STM32H7xx/Include" -I"C:/Users/aymen/Desktop/Kraya/Isac/Chip_Headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

