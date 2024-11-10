################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
DataLink/Notifiers/%.o: ../DataLink/Notifiers/%.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/gcc_arm_none_eabi_9_2_1/bin/arm-none-eabi-gcc-9.2.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fexceptions -DDeviceFamily_MSP432E4 -D__MSP432E401Y__ -I"D:/CodeComposerWorkSpace/LIJN/DataLink/interfaces" -I"D:/CodeComposerWorkSpace/LIJN/DataLink/Notifiers" -I"D:/CodeComposerWorkSpace/LIJN/DataLink/interfaces" -I"D:/CodeComposerWorkSpace/LIJN/storage" -I"D:/CodeComposerWorkSpace/LIJN/storage/db" -I"D:/CodeComposerWorkSpace/LIJN/DataLink/Adapters" -I"D:/CodeComposerWorkSpace/LIJN/DataLink" -I"D:/CodeComposerWorkSpace/LIJN/DataLink/communication" -I"D:/CodeComposerWorkSpace/LIJN/DataLink/frame" -I"D:/CodeComposerWorkSpace/LIJN" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/source" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/source/third_party/CMSIS/Include" -I"C:/ti/simplelink_msp432e4_sdk_4_20_00_12/source/ti/net/bsd" -I"C:/ti/gcc_arm_none_eabi_9_2_1/arm-none-eabi/include/newlib-nano" -I"C:/ti/gcc_arm_none_eabi_9_2_1/arm-none-eabi/include" -O0 -ffunction-sections -fdata-sections -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"DataLink/Notifiers/$(basename $(<F)).d_raw" -MT"$(@)" -std=c++17 -frtti -fno-threadsafe-statics $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


