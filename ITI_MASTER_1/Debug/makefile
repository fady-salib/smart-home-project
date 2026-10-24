################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TMU/subdir.mk
-include SERVICE/subdir.mk
-include MCAL/USART/subdir.mk
-include MCAL/TWI/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/Global_INT/subdir.mk
-include MCAL/GPT_Timer/subdir.mk
-include MCAL/EXT_INT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Step_Motor/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Key_Pad/subdir.mk
-include HAL/EEPROM/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ITI_MASTER_1.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ITI_MASTER_1.elf secondary-outputs

# Tool invocations
ITI_MASTER_1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ITI_MASTER_1.map -mmcu=atmega32 -o "ITI_MASTER_1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ITI_MASTER_1.lss: ITI_MASTER_1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ITI_MASTER_1.elf  >"ITI_MASTER_1.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ITI_MASTER_1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ITI_MASTER_1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ITI_MASTER_1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
