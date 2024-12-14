//
// Created by loitr on 12/14/2024.
//

#ifndef TIMER_4_H
#define TIMER_4_H

/***************  Bit Relative position of APB1ENR register  ******************/
#define TIM4_APB1ENR_ENABLE             0x4      // Bit 2 of the APB1ENR register (count from 0)

/********************* Interrupt and exception vectors (ISER) **********************/
#define ISER_TIM4_GLOBAL_ENR    0x1E      // bit 30 of the register ISER[0]

/**************  common register configuration for TIM  **************/
#include "common_timer_address.h"


/*** Timer mode setup ***/

void TIM4_Internal_Setup(int period_ms);
void TIM4_External_Setup(int period_ms);
void TIM4_Activate(void);
void TIM4_Deactivate(void);

/*** Pulse Width Modulation mode setup ***/

void TIM4_PWM_Channel1_Setup(int period_ms, float duty_cycle);
void TIM4_PWM_Channel2_Setup(int period_ms, float duty_cycle);
void TIM4_PWM_Channel3_Setup(int period_ms, float duty_cycle);
void TIM4_PWM_Channel4_Setup(int period_ms, float duty_cycle);

#endif //TIMER_4_H
