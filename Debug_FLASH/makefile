################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/SWC/subdir.mk
-include src/RTE/subdir.mk
-include src/BSW_CDD_UART/subdir.mk
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
NXP_Autosar_Heat_Seat_Controller.siz \


# All Target
all: NXP_Autosar_Heat_Seat_Controller.elf secondary-outputs

# Tool invocations
NXP_Autosar_Heat_Seat_Controller.elf: $(OBJS) D:/MCAL_Project/NXP_Autosar_Heat_Seat_Controller/Project_Settings/Linker_Files/linker_flash_s32k144.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "NXP_Autosar_Heat_Seat_Controller.elf" "@NXP_Autosar_Heat_Seat_Controller.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

NXP_Autosar_Heat_Seat_Controller.siz: NXP_Autosar_Heat_Seat_Controller.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley NXP_Autosar_Heat_Seat_Controller.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
