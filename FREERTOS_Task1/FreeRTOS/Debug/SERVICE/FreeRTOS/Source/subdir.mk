################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/FreeRTOS/Source/croutine.c \
../SERVICE/FreeRTOS/Source/event_groups.c \
../SERVICE/FreeRTOS/Source/list.c \
../SERVICE/FreeRTOS/Source/queue.c \
../SERVICE/FreeRTOS/Source/stream_buffer.c \
../SERVICE/FreeRTOS/Source/tasks.c \
../SERVICE/FreeRTOS/Source/timers.c 

OBJS += \
./SERVICE/FreeRTOS/Source/croutine.o \
./SERVICE/FreeRTOS/Source/event_groups.o \
./SERVICE/FreeRTOS/Source/list.o \
./SERVICE/FreeRTOS/Source/queue.o \
./SERVICE/FreeRTOS/Source/stream_buffer.o \
./SERVICE/FreeRTOS/Source/tasks.o \
./SERVICE/FreeRTOS/Source/timers.o 

C_DEPS += \
./SERVICE/FreeRTOS/Source/croutine.d \
./SERVICE/FreeRTOS/Source/event_groups.d \
./SERVICE/FreeRTOS/Source/list.d \
./SERVICE/FreeRTOS/Source/queue.d \
./SERVICE/FreeRTOS/Source/stream_buffer.d \
./SERVICE/FreeRTOS/Source/tasks.d \
./SERVICE/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/FreeRTOS/Source/%.o: ../SERVICE/FreeRTOS/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source\include" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source\portable\GCC\ATMega323" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS" -I"D:\NTI\RTOS\FreeRTOS\SERVICE\FreeRTOS\Source" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


