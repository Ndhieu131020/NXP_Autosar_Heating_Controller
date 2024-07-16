################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include board/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
HieuND66_Autosar_ASM.siz \


# All Target
all: HieuND66_Autosar_ASM.elf secondary-outputs

# Tool invocations
HieuND66_Autosar_ASM.elf: $(OBJS) D:/MCAL_Project/HieuND66_Autosar_ASM/Project_Settings/Linker_Files/linker_ram_s32k144.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "HieuND66_Autosar_ASM.elf" "@HieuND66_Autosar_ASM.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

HieuND66_Autosar_ASM.siz: HieuND66_Autosar_ASM.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley HieuND66_Autosar_ASM.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
