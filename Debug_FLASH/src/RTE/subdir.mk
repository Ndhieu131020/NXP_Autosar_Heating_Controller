################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/RTE/RTE.c 

OBJS += \
./src/RTE/RTE.o 

C_DEPS += \
./src/RTE/RTE.d 


# Each subdirectory must supply rules for building sources it contributes
src/RTE/%.o: ../src/RTE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/RTE/RTE.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


