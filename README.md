# STM32_Lib
Create a library for STM32

if files can not be included in `main.h` or `functional_calls.h`, modify this in `CMakeLists.txt`:
`include_directories(Core/Inc Drivers/STM32F1xx_HAL_Driver/Inc
Drivers/STM32F1xx_HAL_Driver/Inc/Legacy Drivers/CMSIS/Device/ST/STM32F1xx/Include
Drivers/CMSIS/Include Project_Library/Inc Project_Library/Register_Address)`