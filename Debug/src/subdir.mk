################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ball.cpp \
../src/Game.cpp \
../src/Player.cpp \
../src/PolkaDotGame.cpp \
../src/Random.cpp 

OBJS += \
./src/Ball.o \
./src/Game.o \
./src/Player.o \
./src/PolkaDotGame.o \
./src/Random.o 

CPP_DEPS += \
./src/Ball.d \
./src/Game.d \
./src/Player.d \
./src/PolkaDotGame.d \
./src/Random.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


