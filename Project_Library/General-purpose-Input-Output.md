# General-purpose Input Output
Each General-purpose Input Output or GPIO port has  two 32-bit configuration registers (GPIOx_CRL,
GPIOx_CRH), two 32-bit data registers (GPIOx_IDR, GPIOx_ODR), a 32-bit set/reset
register (GPIOx_BSRR), a 16-bit reset register (GPIOx_BRR) and a 32-bit locking register
(GPIOx_LCKR). _In this Review Project, we only focus on working with configuration registers and data registers._

### Below is the bus line from the port pin to system bus to Bus matrix, which can be accessed by CPU:

![img.png](imgs/GPIO_busline.png)

All GPIO ports, from A to G, are connected to the same APB2 peripheral bus, which is served by RCC module. Therefore, when working with GPIO, the clock register (
RCC) must be enabled. As we are working with F103C6T8, which only provide two ports A and B. Therefore, we also have these two ports only.

## About configuration registers
A configuration register is a 32-bit register define which define whether a specific port will be input or output or an alternative function.
It also config the mode of that port. For each port, this register has 4 bit, in which, 2 are for configuration (Ouput, Input or Alternative Function)
and the other are for mode (Output maximum speed, Input pull-up pull-down)
### Port configuration register low (GPIOx_CRL)
![img.png](imgs/CRL.png)
### Port configuration register high (GPIOx_CRH)
![img.png](imgs/CRH.png)

## About data registers
A data register is a 32-bit register use to capture or write out a boolean value.
### Port input data register (GPIOx_IDR)
![img.png](imgs/IDR.png)

For IDR register, we can use to read a binary signal from outside.
### Port output data register (GPIOx_ODR)
![img.png](imgs/ODR.png)

For ODR register, we can use to write a binary value out a pin respect to that bit position. In special case, when the port is set
to input pull-up-down, the direction of the input is defined by this register.

## Setup GPIO for a port
1. Enable clock for that port through RCC module.
2. Choose configuration (Input, Output, AF).
3. Choose mode for that configuration.
4. Set CNF-MODE to the register.

## Values for CNF-MODE

* 0x00: **Input Analog**


* 0x01: **General Push Pull at max speed 10MHz**
* 0x02: General Push Pull at max speed 2MHz
* 0x03: General Push Pull at max speed 50MHz

* 0x04: **Input Floating**


* 0x05: **General Open Drain at max speed 10MHz**
* 0x06: General Open Drain at max speed 2MHz
* 0x07: General Open Drain at max speed 50MHz


* 0x08: **Input Pull-up (ODR=1); Pull-down (ODR=0)**


* 0x09: **Alternative Push Pull at max speed 10MHz**
* 0x0A: Alternative Push Pull at max speed 2MHz
* 0x0B: Alternative Push Pull at max speed 50MHz


* 0x0C: **Don't have function**


* 0x0D: **Alternative Open Drain at max speed 10MHz**
* 0x0E: Alternative Open Drain at max speed 2MHz
* 0x0F: Alternative Open Drain at max speed 50MHz