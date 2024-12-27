# STM32_Lib
Create a library for STM32 interacting with its register. This library is build on top HAL framework.

if files can not be included in `main.h` or `functional_calls.h`, modify this in `CMakeLists.txt`:
- **Project_Library/Inc** **Project_Library/Register_Address** to `include_directories()`
- **"Project_Library/*.*"** to `file()`

# Setup Function
All setup and helping function will be included in **[library_setup_conf.h](Core/Inc/library_setup_conf.h)**.  
Modules and Function are managed under this scope, if some module is unused, you can comment it to reduce the flash memory.
## GPIO Module
Implementation script: **[gpio.c](Project_Library/Src/gpio.c)**  
Currently, this library is supporting setup function for port A and port B only.
1. `GPIOx_Setup(int pin, int mode, int cnf)`
   
   Setup pin of a specific port (A or B) with configuration and mode. 
    - `int pin`(0-15): number of pin for that port.
    - `int mode`: mode input or output with 2, 10 or 50MHz.
    - `int cnf`: configuration for a mode.
   
   The configuration and mode for setup is defined in: **[common_gpio_address.h](Project_Library/Register_Address/common_gpio_address.h)**
2. `GPIOx_Pull_Setup(int pin, int pull_up)`
   
   Setup input pull up or pull down for pin of a port (A or B).
   - `int pin`(0-15): number of pin for that port.
   - `int pull_up`: set `0` for pull down and other number for pull up.

## Timer Module
Implementation script: **[timer_1.c](Project_Library/Src/timer_1.c)**, **[timer_4.c](Project_Library/Src/timer_4.c)**  
Setup function for TIM4 only for now.  
Address for Timer common register is defined in: **[common_timer_address.h](Project_Library/Register_Address/common_timer_address.h)** 
1. `TIM4_Internal_Setup(int period_ms)`  
   setup TIM4 with Internal clock source.  
   This function is supported with a helping function given period of time and the clock source,  
   it computes the ARR and PSC value so that, the ARR is maximized
2. `TIM4_External_Setup(int period_ms)`  
   Setup TIM4 with External clock source. (Not tested yet)
3. `TIM4_Activate(void)`  
   Activate the TIM4 by allowing timer's update interrupt flag and Interrupt setup enable in NVIC module. 
4. `TIM4_Deactivate(void)`  
   Deactivate TIM4 by disable timer's interrupt flag and ISER register.
5. `TIM4_PWM_Channelx_Setup(int period_ms, float duty_cycle)`  
   Setup PWM mode for 4 channel TIM4 with mode 1 in default.
6. `TIM4_Counter_Setup(int counts)`  
   Setup counter mode for TIM4, this setup is configured by enable bit 14 in SMCR, default with `PSC = 0`.