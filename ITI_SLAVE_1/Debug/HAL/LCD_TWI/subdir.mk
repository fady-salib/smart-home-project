################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_TWI/LCD_TWI_Prog.c 

OBJS += \
./HAL/LCD_TWI/LCD_TWI_Prog.o 

C_DEPS += \
./HAL/LCD_TWI/LCD_TWI_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_TWI/%.o: ../HAL/LCD_TWI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


