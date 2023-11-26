################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/FreeRTOS/Source/portable/MemMang/heap_1.c 

OBJS += \
./SERVICE/FreeRTOS/Source/portable/MemMang/heap_1.o 

C_DEPS += \
./SERVICE/FreeRTOS/Source/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/FreeRTOS/Source/portable/MemMang/%.o: ../SERVICE/FreeRTOS/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source\include" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source\portable\GCC\ATMega323" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


