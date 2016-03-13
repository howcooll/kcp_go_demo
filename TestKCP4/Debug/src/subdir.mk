################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TestKCP.cpp \
../src/kcp_client.cpp \
../src/kcp_client_util.cpp \
../src/kcp_client_wrap.cpp 

C_SRCS += \
../src/ikcp.c 

OBJS += \
./src/TestKCP.o \
./src/ikcp.o \
./src/kcp_client.o \
./src/kcp_client_util.o \
./src/kcp_client_wrap.o 

C_DEPS += \
./src/ikcp.d 

CPP_DEPS += \
./src/TestKCP.d \
./src/kcp_client.d \
./src/kcp_client_util.d \
./src/kcp_client_wrap.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


