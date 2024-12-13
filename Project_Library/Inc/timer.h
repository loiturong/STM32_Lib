//
// Created by loitr on 12/11/2024.
//

#ifndef TIMER_H
#define TIMER_H

// Helping function
int *compute_value(int period_ms, int frequency);

// Timer mode
void TIM1_Internal_Setup(int period_ms);
void TIM2_Internal_Setup(int period_ms);
// void TIM3_Internal_Setup(int period_ms);
// void TIM4_Internal_Setup(int period_ms);
// void TIM5_Internal_Setup(int period_ms);

void TIM1_External_Setup(int period_ms);
void TIM2_External_Setup(int period_ms);
// void TIM3_External_Setup(int period_ms);
// void TIM4_External_Setup(int period_ms);
// void TIM5_External_Setup(int period_ms);


void TIM1_Activate(void);
void TIM2_Activate(void);
// void TIM3_Activate(void);
// void TIM4_Activate(void);
// void TIM5_Activate(void);
// void TIM6_Activate(void);

// PWM mode
void TIM1_PWM_Setup(void);

void TIM2_PWM_Channel1_Setup(int period_ms, float duty_cycle);
void TIM2_PWM_Channel2_Setup(int period_ms, float duty_cycle);
void TIM2_PWM_Channel3_Setup(int period_ms, float duty_cycle);
void TIM2_PWM_Channel4_Setup(int period_ms, float duty_cycle);

#endif //TIMER_H
