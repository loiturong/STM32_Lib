//
// Created by loitr on 12/14/2024.
//

#ifndef TIMER_2_H
#define TIMER_2_H

/***************  Bit Relative position of APB1ENR register  ******************/
#define TIM2_APB1ENR_ENABLE     0x1      // Bit 0 of the APB1ENR register

/********************* Interrupt and exception vectors (ISER) **********************/
#define ISER_TIM2_GLOBAL_ENR    0x1C      // bit 28 of the register ISER[0]

/**************  common register configuration for TIM  **************/
#include "common_timer_address.h"

void TIM2_Internal_Setup(int period_ms);
void TIM2_External_Setup(int period_ms);
void TIM2_Activate(void);
void TIM2_Deactivate(void);
void TIM2_PWM_Channel1_Setup(int period_ms, float duty_cycle);
void TIM2_PWM_Channel2_Setup(int period_ms, float duty_cycle);
void TIM2_PWM_Channel3_Setup(int period_ms, float duty_cycle);
void TIM2_PWM_Channel4_Setup(int period_ms, float duty_cycle);

#endif //TIMER_2_H
