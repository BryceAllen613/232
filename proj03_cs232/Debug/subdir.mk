################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BSShell.cpp \
../CommandLine.cpp \
../Path.cpp \
../Project3.2.cpp \
../Prompt.cpp 

OBJS += \
./BSShell.o \
./CommandLine.o \
./Path.o \
./Project3.2.o \
./Prompt.o 

CPP_DEPS += \
./BSShell.d \
./CommandLine.d \
./Path.d \
./Project3.2.d \
./Prompt.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


