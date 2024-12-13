//
// Created by loitr on 12/11/2024.
//

#ifndef TIMER_H
#define TIMER_H

// Helping function
int *compute_value(int period_ms, int frequency);

// Timer mode

void TIM1_Setup(int period_ms, int frequency);
void TIM2_Setup(int period_ms, int frequency);
// void TIM3_Setup(int period_ms, int frequency);
// void TIM4_Setup(int period_ms, int frequency);
// void TIM5_Setup(int period_ms, int frequency);
// void TIM6_Setup(int period_ms, int frequency);

void TIM1_Activate(void);
void TIM2_Activate(void);
// void TIM3_Activate(void);
// void TIM4_Activate(void);
// void TIM5_Activate(void);
// void TIM6_Activate(void);

// PWM mode
void TIM1_PWM_Setup(void);

#endif //TIMER_H
