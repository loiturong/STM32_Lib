//
// Created by loitr on 12/14/2024.
//

#ifndef TIMER_1_H
#define TIMER_1_H

void TIM1_Internal_Setup(int period_ms);
void TIM1_External_Setup(int period_ms);
void TIM1_Activate(void);
void TIM1_Deactivate(void);
void TIM1_PWM_Channel_1_Setup(int period_ms, float duty_cycle);

#endif //TIMER_1_H
