//
// Created by loitr on 12/11/2024.
//

#ifndef TIMER_H
#define TIMER_H

// register
/***************  Bit Relative position of APB1ENR register  ******************/
#define TIM2_APB1ENR_ENABLE     0x1      // Bit 0 of the APB1ENR register
#define TIM4_APB1ENR_ENABLE     0x4      // Bit 2 of the APB1ENR register (count from 0)

/********************* Interrupt and exception vectors (ISER) **********************/
#define ISER_TIM2_GLOBAL_ENR    0x1C      // bit 28 of the register ISER[0]
#define ISER_TIM4_GLOBAL_ENR    0x1E      // bit 30 of the register ISER[0]

/**************  common register configuration for TIM  **************/
#include "common_timer_address.h"



/*** Helping function ***/

int *find_timer_configuration(int period_ms, int frequency);

/*** Timer mode setup ***/

// void TIM1_Internal_Setup(int period_ms);
// void TIM1_External_Setup(int period_ms);
// void TIM1_Activate(void);
// void TIM1_Deactivate(void);

void TIM2_Setup(int period_ms);
void TIM2_Activate(void);
void TIM2_Deactivate(void);

void TIM4_Setup(int period_ms);
void TIM4_Activate(void);
void TIM4_Deactivate(void);

/*** Pulse Width Modulation mode setup ***/

// void TIM1_PWM_Channel_1_Setup(int period_ms, float duty_cycle);

void TIM2_PWM_Channel1_Setup(int period_ms, float duty_cycle);
// void TIM2_PWM_Channel2_Setup(int period_ms, float duty_cycle);
// void TIM2_PWM_Channel3_Setup(int period_ms, float duty_cycle);
// void TIM2_PWM_Channel4_Setup(int period_ms, float duty_cycle);

void TIM4_PWM_Channel1_Setup(int period_ms, float duty_cycle);
void TIM4_PWM_Channel2_Setup(int period_ms, float duty_cycle);
void TIM4_PWM_Channel3_Setup(int period_ms, float duty_cycle);
void TIM4_PWM_Channel4_Setup(int period_ms, float duty_cycle);

/*** Counter mode setup ***/

void TIM4_Counter_Setup(int counts);

#endif //TIMER_H
