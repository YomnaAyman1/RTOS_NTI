################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Ultrasonic/SOURCE/ultrasonic.c 

OBJS += \
./HAL/Ultrasonic/SOURCE/ultrasonic.o 

C_DEPS += \
./HAL/Ultrasonic/SOURCE/ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Ultrasonic/SOURCE/%.o: ../HAL/Ultrasonic/SOURCE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source\include" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source\portable\GCC\ATMega323" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


