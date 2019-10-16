################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CommandLineController.cpp \
../CommandLineView.cpp \
../Model.cpp \
../TextBasedController.cpp \
../TextBasedView.cpp \
../callTimer.cpp 

OBJS += \
./CommandLineController.o \
./CommandLineView.o \
./Model.o \
./TextBasedController.o \
./TextBasedView.o \
./callTimer.o 

CPP_DEPS += \
./CommandLineController.d \
./CommandLineView.d \
./Model.d \
./TextBasedController.d \
./TextBasedView.d \
./callTimer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


