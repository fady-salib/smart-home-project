################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TMU/COTS/HAL/EEPROM/EEPROM_Prog.c 

OBJS += \
./TMU/COTS/HAL/EEPROM/EEPROM_Prog.o 

C_DEPS += \
./TMU/COTS/HAL/EEPROM/EEPROM_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
TMU/COTS/HAL/EEPROM/%.o: ../TMU/COTS/HAL/EEPROM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


