################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/InteractiveLCD_Prog.c \
../SERVICE/Security_Prog.c \
../SERVICE/Services_Prog.c 

OBJS += \
./SERVICE/InteractiveLCD_Prog.o \
./SERVICE/Security_Prog.o \
./SERVICE/Services_Prog.o 

C_DEPS += \
./SERVICE/InteractiveLCD_Prog.d \
./SERVICE/Security_Prog.d \
./SERVICE/Services_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/%.o: ../SERVICE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


