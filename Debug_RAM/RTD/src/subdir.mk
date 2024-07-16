################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTD/src/Adc.c \
../RTD/src/Adc_Ip.c \
../RTD/src/Adc_Ip_Irq.c \
../RTD/src/Adc_Ipw.c \
../RTD/src/Adc_Ipw_Irq.c \
../RTD/src/Clock_Ip.c \
../RTD/src/Clock_Ip_Data.c \
../RTD/src/Clock_Ip_Divider.c \
../RTD/src/Clock_Ip_DividerTrigger.c \
../RTD/src/Clock_Ip_ExtOsc.c \
../RTD/src/Clock_Ip_FracDiv.c \
../RTD/src/Clock_Ip_Frequency.c \
../RTD/src/Clock_Ip_Gate.c \
../RTD/src/Clock_Ip_IntOsc.c \
../RTD/src/Clock_Ip_Irq.c \
../RTD/src/Clock_Ip_Monitor.c \
../RTD/src/Clock_Ip_Pll.c \
../RTD/src/Clock_Ip_ProgFreqSwitch.c \
../RTD/src/Clock_Ip_Selector.c \
../RTD/src/Clock_Ip_Specific.c \
../RTD/src/Det.c \
../RTD/src/Dio.c \
../RTD/src/Dio_Ipw.c \
../RTD/src/Ftm_Gpt_Ip.c \
../RTD/src/Gpio_Dio_Ip.c \
../RTD/src/Gpt.c \
../RTD/src/Gpt_Ipw.c \
../RTD/src/IntCtrl_Ip.c \
../RTD/src/LPit_Gpt_Ip.c \
../RTD/src/Lptmr_Gpt_Ip.c \
../RTD/src/Mcu.c \
../RTD/src/Mcu_Dem_Wrapper.c \
../RTD/src/Mcu_Ipw.c \
../RTD/src/Mcu_Ipw_Irq.c \
../RTD/src/Mpu_Ip.c \
../RTD/src/OsIf_Interrupts.c \
../RTD/src/OsIf_Timer.c \
../RTD/src/OsIf_Timer_System.c \
../RTD/src/OsIf_Timer_System_Internal_Systick.c \
../RTD/src/Pdb_Adc_Ip.c \
../RTD/src/Pdb_Adc_Ip_Irq.c \
../RTD/src/Platform.c \
../RTD/src/Platform_Ipw.c \
../RTD/src/Port.c \
../RTD/src/Port_Ci_Port_Ip.c \
../RTD/src/Port_Ipw.c \
../RTD/src/Power_Ip.c \
../RTD/src/Power_Ip_AEC.c \
../RTD/src/Power_Ip_CortexM4.c \
../RTD/src/Power_Ip_PMC.c \
../RTD/src/Power_Ip_PMC_Irq.c \
../RTD/src/Power_Ip_Private.c \
../RTD/src/Power_Ip_RCM.c \
../RTD/src/Power_Ip_RCM_Irq.c \
../RTD/src/Power_Ip_SIM.c \
../RTD/src/Power_Ip_SMC.c \
../RTD/src/Ram_Ip.c \
../RTD/src/SRtc_Ip.c \
../RTD/src/SchM_Adc.c \
../RTD/src/SchM_Dio.c \
../RTD/src/SchM_Gpt.c \
../RTD/src/SchM_Mcu.c \
../RTD/src/SchM_Platform.c \
../RTD/src/SchM_Port.c \
../RTD/src/System_Ip.c 

OBJS += \
./RTD/src/Adc.o \
./RTD/src/Adc_Ip.o \
./RTD/src/Adc_Ip_Irq.o \
./RTD/src/Adc_Ipw.o \
./RTD/src/Adc_Ipw_Irq.o \
./RTD/src/Clock_Ip.o \
./RTD/src/Clock_Ip_Data.o \
./RTD/src/Clock_Ip_Divider.o \
./RTD/src/Clock_Ip_DividerTrigger.o \
./RTD/src/Clock_Ip_ExtOsc.o \
./RTD/src/Clock_Ip_FracDiv.o \
./RTD/src/Clock_Ip_Frequency.o \
./RTD/src/Clock_Ip_Gate.o \
./RTD/src/Clock_Ip_IntOsc.o \
./RTD/src/Clock_Ip_Irq.o \
./RTD/src/Clock_Ip_Monitor.o \
./RTD/src/Clock_Ip_Pll.o \
./RTD/src/Clock_Ip_ProgFreqSwitch.o \
./RTD/src/Clock_Ip_Selector.o \
./RTD/src/Clock_Ip_Specific.o \
./RTD/src/Det.o \
./RTD/src/Dio.o \
./RTD/src/Dio_Ipw.o \
./RTD/src/Ftm_Gpt_Ip.o \
./RTD/src/Gpio_Dio_Ip.o \
./RTD/src/Gpt.o \
./RTD/src/Gpt_Ipw.o \
./RTD/src/IntCtrl_Ip.o \
./RTD/src/LPit_Gpt_Ip.o \
./RTD/src/Lptmr_Gpt_Ip.o \
./RTD/src/Mcu.o \
./RTD/src/Mcu_Dem_Wrapper.o \
./RTD/src/Mcu_Ipw.o \
./RTD/src/Mcu_Ipw_Irq.o \
./RTD/src/Mpu_Ip.o \
./RTD/src/OsIf_Interrupts.o \
./RTD/src/OsIf_Timer.o \
./RTD/src/OsIf_Timer_System.o \
./RTD/src/OsIf_Timer_System_Internal_Systick.o \
./RTD/src/Pdb_Adc_Ip.o \
./RTD/src/Pdb_Adc_Ip_Irq.o \
./RTD/src/Platform.o \
./RTD/src/Platform_Ipw.o \
./RTD/src/Port.o \
./RTD/src/Port_Ci_Port_Ip.o \
./RTD/src/Port_Ipw.o \
./RTD/src/Power_Ip.o \
./RTD/src/Power_Ip_AEC.o \
./RTD/src/Power_Ip_CortexM4.o \
./RTD/src/Power_Ip_PMC.o \
./RTD/src/Power_Ip_PMC_Irq.o \
./RTD/src/Power_Ip_Private.o \
./RTD/src/Power_Ip_RCM.o \
./RTD/src/Power_Ip_RCM_Irq.o \
./RTD/src/Power_Ip_SIM.o \
./RTD/src/Power_Ip_SMC.o \
./RTD/src/Ram_Ip.o \
./RTD/src/SRtc_Ip.o \
./RTD/src/SchM_Adc.o \
./RTD/src/SchM_Dio.o \
./RTD/src/SchM_Gpt.o \
./RTD/src/SchM_Mcu.o \
./RTD/src/SchM_Platform.o \
./RTD/src/SchM_Port.o \
./RTD/src/System_Ip.o 

C_DEPS += \
./RTD/src/Adc.d \
./RTD/src/Adc_Ip.d \
./RTD/src/Adc_Ip_Irq.d \
./RTD/src/Adc_Ipw.d \
./RTD/src/Adc_Ipw_Irq.d \
./RTD/src/Clock_Ip.d \
./RTD/src/Clock_Ip_Data.d \
./RTD/src/Clock_Ip_Divider.d \
./RTD/src/Clock_Ip_DividerTrigger.d \
./RTD/src/Clock_Ip_ExtOsc.d \
./RTD/src/Clock_Ip_FracDiv.d \
./RTD/src/Clock_Ip_Frequency.d \
./RTD/src/Clock_Ip_Gate.d \
./RTD/src/Clock_Ip_IntOsc.d \
./RTD/src/Clock_Ip_Irq.d \
./RTD/src/Clock_Ip_Monitor.d \
./RTD/src/Clock_Ip_Pll.d \
./RTD/src/Clock_Ip_ProgFreqSwitch.d \
./RTD/src/Clock_Ip_Selector.d \
./RTD/src/Clock_Ip_Specific.d \
./RTD/src/Det.d \
./RTD/src/Dio.d \
./RTD/src/Dio_Ipw.d \
./RTD/src/Ftm_Gpt_Ip.d \
./RTD/src/Gpio_Dio_Ip.d \
./RTD/src/Gpt.d \
./RTD/src/Gpt_Ipw.d \
./RTD/src/IntCtrl_Ip.d \
./RTD/src/LPit_Gpt_Ip.d \
./RTD/src/Lptmr_Gpt_Ip.d \
./RTD/src/Mcu.d \
./RTD/src/Mcu_Dem_Wrapper.d \
./RTD/src/Mcu_Ipw.d \
./RTD/src/Mcu_Ipw_Irq.d \
./RTD/src/Mpu_Ip.d \
./RTD/src/OsIf_Interrupts.d \
./RTD/src/OsIf_Timer.d \
./RTD/src/OsIf_Timer_System.d \
./RTD/src/OsIf_Timer_System_Internal_Systick.d \
./RTD/src/Pdb_Adc_Ip.d \
./RTD/src/Pdb_Adc_Ip_Irq.d \
./RTD/src/Platform.d \
./RTD/src/Platform_Ipw.d \
./RTD/src/Port.d \
./RTD/src/Port_Ci_Port_Ip.d \
./RTD/src/Port_Ipw.d \
./RTD/src/Power_Ip.d \
./RTD/src/Power_Ip_AEC.d \
./RTD/src/Power_Ip_CortexM4.d \
./RTD/src/Power_Ip_PMC.d \
./RTD/src/Power_Ip_PMC_Irq.d \
./RTD/src/Power_Ip_Private.d \
./RTD/src/Power_Ip_RCM.d \
./RTD/src/Power_Ip_RCM_Irq.d \
./RTD/src/Power_Ip_SIM.d \
./RTD/src/Power_Ip_SMC.d \
./RTD/src/Ram_Ip.d \
./RTD/src/SRtc_Ip.d \
./RTD/src/SchM_Adc.d \
./RTD/src/SchM_Dio.d \
./RTD/src/SchM_Gpt.d \
./RTD/src/SchM_Mcu.d \
./RTD/src/SchM_Platform.d \
./RTD/src/SchM_Port.d \
./RTD/src/System_Ip.d 


# Each subdirectory must supply rules for building sources it contributes
RTD/src/%.o: ../RTD/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@RTD/src/Adc.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


