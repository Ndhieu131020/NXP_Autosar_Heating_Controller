################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SWC/SWC_Actuator_LedController.c \
../src/SWC/SWC_Color_Controller.c \
../src/SWC/SWC_Override_Color.c \
../src/SWC/SWC_SensorPotentiometer.c \
../src/SWC/SWC_SystemInit.c \
../src/SWC/SWC_TaskManager.c 

OBJS += \
./src/SWC/SWC_Actuator_LedController.o \
./src/SWC/SWC_Color_Controller.o \
./src/SWC/SWC_Override_Color.o \
./src/SWC/SWC_SensorPotentiometer.o \
./src/SWC/SWC_SystemInit.o \
./src/SWC/SWC_TaskManager.o 

C_DEPS += \
./src/SWC/SWC_Actuator_LedController.d \
./src/SWC/SWC_Color_Controller.d \
./src/SWC/SWC_Override_Color.d \
./src/SWC/SWC_SensorPotentiometer.d \
./src/SWC/SWC_SystemInit.d \
./src/SWC/SWC_TaskManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/SWC/%.o: ../src/SWC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/SWC/SWC_Actuator_LedController.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


