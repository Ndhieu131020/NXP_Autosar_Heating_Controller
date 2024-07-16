################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generate/src/Adc_Cfg.c \
../generate/src/Adc_Ip_PBcfg.c \
../generate/src/Adc_Ipw_PBcfg.c \
../generate/src/Adc_PBcfg.c \
../generate/src/Clock_Ip_Cfg.c \
../generate/src/Clock_Ip_PBcfg.c \
../generate/src/Dio_Cfg.c \
../generate/src/Ftm_Gpt_Ip_PBcfg.c \
../generate/src/Gpt_Cfg.c \
../generate/src/Gpt_Ipw_PBcfg.c \
../generate/src/Gpt_PBcfg.c \
../generate/src/IntCtrl_Ip_Cfg.c \
../generate/src/LPit_Gpt_Ip_PBcfg.c \
../generate/src/Lptmr_Gpt_Ip_PBcfg.c \
../generate/src/Mcu_Cfg.c \
../generate/src/Mcu_PBcfg.c \
../generate/src/Mpu_Ip_Cfg.c \
../generate/src/OsIf_Cfg.c \
../generate/src/Pdb_Adc_Ip_PBcfg.c \
../generate/src/Platform_Cfg.c \
../generate/src/Platform_Ipw_Cfg.c \
../generate/src/Port_Cfg.c \
../generate/src/Port_Ci_Port_Ip_PBcfg.c \
../generate/src/Port_PBcfg.c \
../generate/src/Power_Ip_Cfg.c \
../generate/src/Power_Ip_PBcfg.c \
../generate/src/Ram_Ip_Cfg.c \
../generate/src/Ram_Ip_PBcfg.c \
../generate/src/SRtc_Ip_PBcfg.c 

OBJS += \
./generate/src/Adc_Cfg.o \
./generate/src/Adc_Ip_PBcfg.o \
./generate/src/Adc_Ipw_PBcfg.o \
./generate/src/Adc_PBcfg.o \
./generate/src/Clock_Ip_Cfg.o \
./generate/src/Clock_Ip_PBcfg.o \
./generate/src/Dio_Cfg.o \
./generate/src/Ftm_Gpt_Ip_PBcfg.o \
./generate/src/Gpt_Cfg.o \
./generate/src/Gpt_Ipw_PBcfg.o \
./generate/src/Gpt_PBcfg.o \
./generate/src/IntCtrl_Ip_Cfg.o \
./generate/src/LPit_Gpt_Ip_PBcfg.o \
./generate/src/Lptmr_Gpt_Ip_PBcfg.o \
./generate/src/Mcu_Cfg.o \
./generate/src/Mcu_PBcfg.o \
./generate/src/Mpu_Ip_Cfg.o \
./generate/src/OsIf_Cfg.o \
./generate/src/Pdb_Adc_Ip_PBcfg.o \
./generate/src/Platform_Cfg.o \
./generate/src/Platform_Ipw_Cfg.o \
./generate/src/Port_Cfg.o \
./generate/src/Port_Ci_Port_Ip_PBcfg.o \
./generate/src/Port_PBcfg.o \
./generate/src/Power_Ip_Cfg.o \
./generate/src/Power_Ip_PBcfg.o \
./generate/src/Ram_Ip_Cfg.o \
./generate/src/Ram_Ip_PBcfg.o \
./generate/src/SRtc_Ip_PBcfg.o 

C_DEPS += \
./generate/src/Adc_Cfg.d \
./generate/src/Adc_Ip_PBcfg.d \
./generate/src/Adc_Ipw_PBcfg.d \
./generate/src/Adc_PBcfg.d \
./generate/src/Clock_Ip_Cfg.d \
./generate/src/Clock_Ip_PBcfg.d \
./generate/src/Dio_Cfg.d \
./generate/src/Ftm_Gpt_Ip_PBcfg.d \
./generate/src/Gpt_Cfg.d \
./generate/src/Gpt_Ipw_PBcfg.d \
./generate/src/Gpt_PBcfg.d \
./generate/src/IntCtrl_Ip_Cfg.d \
./generate/src/LPit_Gpt_Ip_PBcfg.d \
./generate/src/Lptmr_Gpt_Ip_PBcfg.d \
./generate/src/Mcu_Cfg.d \
./generate/src/Mcu_PBcfg.d \
./generate/src/Mpu_Ip_Cfg.d \
./generate/src/OsIf_Cfg.d \
./generate/src/Pdb_Adc_Ip_PBcfg.d \
./generate/src/Platform_Cfg.d \
./generate/src/Platform_Ipw_Cfg.d \
./generate/src/Port_Cfg.d \
./generate/src/Port_Ci_Port_Ip_PBcfg.d \
./generate/src/Port_PBcfg.d \
./generate/src/Power_Ip_Cfg.d \
./generate/src/Power_Ip_PBcfg.d \
./generate/src/Ram_Ip_Cfg.d \
./generate/src/Ram_Ip_PBcfg.d \
./generate/src/SRtc_Ip_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
generate/src/%.o: ../generate/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@generate/src/Adc_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


