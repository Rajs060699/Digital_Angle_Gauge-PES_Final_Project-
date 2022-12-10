################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/I2C.c \
../source/LED.c \
../source/MMA8451Q.c \
../source/Systick.c \
../source/cbfifo.c \
../source/main.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/statemachine.c \
../source/switch.c \
../source/sysclock.c \
../source/test_angle_detect.c \
../source/test_cbfifo.c \
../source/test_led_pwm.c \
../source/test_suite.c \
../source/uart.c 

C_DEPS += \
./source/I2C.d \
./source/LED.d \
./source/MMA8451Q.d \
./source/Systick.d \
./source/cbfifo.d \
./source/main.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/statemachine.d \
./source/switch.d \
./source/sysclock.d \
./source/test_angle_detect.d \
./source/test_cbfifo.d \
./source/test_led_pwm.d \
./source/test_suite.d \
./source/uart.d 

OBJS += \
./source/I2C.o \
./source/LED.o \
./source/MMA8451Q.o \
./source/Systick.o \
./source/cbfifo.o \
./source/main.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/statemachine.o \
./source/switch.o \
./source/sysclock.o \
./source/test_angle_detect.o \
./source/test_cbfifo.o \
./source/test_led_pwm.o \
./source/test_suite.o \
./source/uart.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DPRINTF_FLOAT_ENABLE=1 -DCR_PRINTF_CHAR -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=1 -I"C:\Users\Rajesh\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Final_Project\board" -I"C:\Users\Rajesh\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Final_Project\source" -I"C:\Users\Rajesh\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Final_Project" -I"C:\Users\Rajesh\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Final_Project\drivers" -I"C:\Users\Rajesh\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Final_Project\CMSIS" -I"C:\Users\Rajesh\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Final_Project\utilities" -I"C:\Users\Rajesh\Documents\MCUXpressoIDE_11.6.0_8187\workspace\PES_Final_Project\startup" -O0 -fno-common -g3 -Wall -Werror -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/I2C.d ./source/I2C.o ./source/LED.d ./source/LED.o ./source/MMA8451Q.d ./source/MMA8451Q.o ./source/Systick.d ./source/Systick.o ./source/cbfifo.d ./source/cbfifo.o ./source/main.d ./source/main.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/statemachine.d ./source/statemachine.o ./source/switch.d ./source/switch.o ./source/sysclock.d ./source/sysclock.o ./source/test_angle_detect.d ./source/test_angle_detect.o ./source/test_cbfifo.d ./source/test_cbfifo.o ./source/test_led_pwm.d ./source/test_led_pwm.o ./source/test_suite.d ./source/test_suite.o ./source/uart.d ./source/uart.o

.PHONY: clean-source

