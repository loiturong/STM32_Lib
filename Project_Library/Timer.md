# Timer
Timer is a part of peripheral of Microcontroller working independently with CPU.
Most timer is in APB1 peripheral except for TIM1, which is in APB2.

![img.img](imgs/GPIO_busline.png)

## Functions of a Timer
- Timer mode
- Counter mode
- PWM mode
- Input capture mode


Timer has two clock sources:
- Internal clock: RCC module from Microcontroller (timer mode)
- External clock: reading external event (counter mode)

## Timer mode
using these 16-bit register:
- Counter register (`TIMx_CNT`)
- Prescaler register (`TIMx_PSC`)
- Auto-Reload register (`TIMx_ARR`)

In which CNT is the register to store the current value of a timer, compare with ARR, when the CNT is at ARR preset value,
it is reset. For PSC and ARR is any between 1 and 65536, we can calculate the period of one cycle as:

$T_f = \frac{1}{f}\times(PSC+1)\times(ARR+1)$

## Setup Timer for Timer mode

1. Enable Clock for Timer (`RCC->APB1` or `RCC->APB2` for TIM1)
2. Set Prescaler and Auto-Reload for timer (perform computing to get desire values)
3. Enable auto-reload preload enable bit (ARPE) in TIMx_CR1 register. (bit 0)
4. Enable using Update Interrupt (UI)
5. Enable Interrupt setup enable register in NVIC module (`NVIC->ISER`), each timer have a different place in the ISER vector.
6. Setting Interrupt Handler function (`void TIMx_IRQHandler(void)`)