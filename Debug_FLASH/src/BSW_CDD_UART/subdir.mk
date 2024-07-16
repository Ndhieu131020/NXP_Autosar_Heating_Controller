################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BSW_CDD_UART/CDD_UARTManager.c \
../src/BSW_CDD_UART/CDD_UARTManager_Queue.c \
../src/BSW_CDD_UART/HAL_S32K144_LPUART.c 

OBJS += \
./src/BSW_CDD_UART/CDD_UARTManager.o \
./src/BSW_CDD_UART/CDD_UARTManager_Queue.o \
./src/BSW_CDD_UART/HAL_S32K144_LPUART.o 

C_DEPS += \
./src/BSW_CDD_UART/CDD_UARTManager.d \
./src/BSW_CDD_UART/CDD_UARTManager_Queue.d \
./src/BSW_CDD_UART/HAL_S32K144_LPUART.d 


# Each subdirectory must supply rules for building sources it contributes
src/BSW_CDD_UART/%.o: ../src/BSW_CDD_UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/BSW_CDD_UART/CDD_UARTManager.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


